import sys
import cv2
import threading
import qimage2ndarray
import numpy as np
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *   
import urllib.request       
from PyQt5 import uic
from PyQt5 import QtWidgets
from PyQt5 import QtGui
from PyQt5 import QtCore
from PyQt5.QtGui import QPixmap
from PyQt5.QtGui import QImage
from PyQt5.QtCore import Qt, QSize

form_class = uic.loadUiType("C:/photo_final/photo.ui")[0]

class photoWindow(QMainWindow, form_class) : # 사진 편집 기능
    
    global image
    global qImg
    global pixmap    
    global originPixmap
    global isOrigin 
    global isGray
    isGray = False
    # global isDragging
    # global x0, y0, w, h
    # isDragging = False
    
    
    def __init__(self) :
        super().__init__()
        self.setupUi(self)
        self.loadButton.clicked.connect(self.fileopen) # 사진 불러오기 버튼
        self.revLRButton.clicked.connect(self.revLR) # 좌우반전 버튼
        self.revUDButton.clicked.connect(self.revUD) # 상하반전 버튼
        self.grayButton.clicked.connect(self.grayScale) # 흑백 버튼
        self.huiButton.clicked.connect(self.hui) # 휘도 버튼
        self.originButton.clicked.connect(self.origin) # 원본이미지 버튼
        self.mosaicButton.clicked.connect(self.mosaic) # 모자이크 버튼
        self.turnButton.clicked.connect(self.turn) # 회전 버튼
        self.blurButton.clicked.connect(self.blur) #블러 버튼
        self.saveButton.clicked.connect(self.save) # 저장 버튼
        self.roiButton.clicked.connect(self.cut) # 사진 자르기 버튼
        self.brightButton.clicked.connect(self.bright) # 밝기 버튼
        self.sharpButton.clicked.connect(self.sharp) # 선명하게 버튼
        self.outlineButton.clicked.connect(self.outline) # 외곽선 추출 버튼
        self.homeButton.clicked.connect(self.home) # home화면 버튼


    def fileopen(self) : # 사진 불러오기
        global filename 
        filename = QtWidgets.QFileDialog.getOpenFileName(self, "Open File", '', '사진(*.jpg; *jpeg; *png)') # 파일 이름 가져오기
        self.pixmap = QPixmap(filename[0]) # pixmap 변수에 filename[0] 즉 경로에 있는 사진 저장
        self.pixmap = self.pixmap.scaled(QSize(500,500), Qt.KeepAspectRatio, transformMode = Qt.SmoothTransformation)
        self.image = cv2.imread(filename[0]) # 파일에서 불러온 이미지 저장
        self.image = cv2.cvtColor(self.image, cv2.COLOR_BGR2RGB)
        self.originPixmap = self.pixmap
        self.label.setPixmap(self.pixmap)

    def showImage(self, img) : # 이미지 보여주기 함수(편집된 이미지도 볼 수 있음)
        self.qImg = qimage2ndarray.array2qimage(img, normalize=False)
        self.pixmap = QtGui.QPixmap.fromImage(self.qImg)
        self.pixmap = self.pixmap.scaled(QSize(500,500), Qt.KeepAspectRatio, transformMode = Qt.SmoothTransformation)
        self.label.setPixmap(self.pixmap)


    def grayScale(self) : # 흑백 버튼
        src = self.image
        gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY) # bgr 이미지를 gray로 바꿈
        self.image = gray
        self.showImage(gray)  
        self.isGray = True
        
    
    def revLR(self) : #좌우 반전
        img = cv2.flip(self.image, 1)
        self.image = img
        self.showImage(img)

    def revUD(self) : # 상하반전
        img = cv2.flip(self.image, 0)
        self.image = img
        self.showImage(img)

    def origin(self) : #원본 이미지 보여주기
        self.label_2.setPixmap(self.originPixmap)
        

    def turn(self) : # 사진 회전하기
        self.image = cv2.rotate(self.image, cv2.ROTATE_90_CLOCKWISE)
        self.showImage(self.image)

    def blur(self) : # 블러처리
        img = cv2.GaussianBlur(self.image, (5, 5), 0)
        self.image = img
        self.showImage(self.image)   

    # def mousePressEvent(self, event) :
    #     self.x0 = event.x()
    #     self.y0 = event.y()
    #     self.isDragging = True
    #     print(self.x0)

    # def mouseReleaseEvent(self, event) :
    #     self.w = event.x()
    #     self.h = event.y()
    #     self.isDragging = False
    #     print(self.w)

    # def mosaic(self) :
    #   rate = 10
    #   while isDragging :
    #     src = self.image.copy()
    #     if self.w and self.h :
    #         src = src[self.y0 : self.y0+self.h, self.x0 : self.x0+self.w]
    #         src = cv2.resize(src, (self.w // rate, self.h//rate))
    #         src = cv2.resize(src, (self.w, self.h), interpolation=cv2.INTER_AREA)
    #         src[self.y0 : self.y0+self.h, self.x0 : self.x0+self.w] = src
    #         originalImage = QtGui.QImage(src.data, src.shape[1], src.shape[0], QtGui.QImage.Format_RGB888)
    #         originpixmap = QtGui.QPixmap.fromImage(originalImage)
    #         self.label_2.setPixmap(originpixmap)
    #         self.image = src
    #         #self.showImage(self.image)
    #     else :
    #         break

    def mosaic(self) : #모자이크
        rate = 10
        while True :
            src = self.image.copy()
            x, y, w, h = cv2.selectROI('mosaic', cv2.cvtColor(src, cv2.COLOR_RGB2BGR), False)
            if w and h :
                roi = src[y:y+h, x:x+w]
                roi = cv2.resize(roi, (w//rate, h//rate)) #사진 축소
                roi = cv2.resize(roi, (w,h), interpolation=cv2.INTER_AREA) #사진 다시 원래 크기로 확대
                src[y:y+h, x:x+w] = roi
                self.image = src
                self.showImage(self.image)
                cv2.waitKey(0)
                cv2.destroyAllWindows()
            else :
                break

    def save(self) :# 편집한 이미지 사진 저장
        self.image = cv2.cvtColor(self.image, cv2.COLOR_BGR2RGB)
        self.fname, _ = QFileDialog.getSaveFileName(self, 'Save Image Files', './', 'image files(*.jpg)' , options = QFileDialog.DontUseNativeDialog)
        cv2.imwrite(self.fname, self.image)

    def cut(self) : #이미지 자르기
        src = self.image
        x, y, w, h = cv2.selectROI('cut_image', cv2.cvtColor(src, cv2.COLOR_RGB2BGR), False)
        if w and h :
            roi = src[y:y+h, x:x+w]
            self.image = roi
            self.showImage(self.image)

    def sharp(self) :
        sharpening = np.array([0, -1, 0,
                              -1, 5, -1,
                               0, -1, 0])
        sharpened = cv2.filter2D(self.image, -1, sharpening)
        self.image = sharpened
        self.showImage(self.image)

    def hui(self) :
        alpha1 = -0.05
        alpha2 = 0.05
        if(self.plusButton.isChecked() == True) :
            self.image = np.clip((1+alpha2) * self.image, 0, 255).astype(np.uint8)
        elif(self.minusButton.isChecked() == True) :
            self.image = np.clip((1+alpha1) * self.image, 0, 255).astype(np.uint8)
        self.showImage(self.image)
        
    def bright(self) :
        k = 10
        array = np.full(self.image.shape, (k, k, k), dtype = np.uint8)
        if(self.brButton.isChecked() == True) :
            self.image = cv2.add(self.image, array)
        elif(self.darkButton.isChecked() == True) :
            self.image = cv2.subtract(self.image, array)
        self.showImage(self.image)

    def outline(self) :
        edges = cv2.Canny(self.image, 70, 140)
        edges = 255-edges
        self.image = edges
        self.showImage(self.image)

    def home(self) :
        self.hide()

if __name__ == "__main__" :
    app = QApplication(sys.argv) 
    myWindow = photoWindow() 
    myWindow.show()
    app.exec_()
