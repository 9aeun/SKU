import sys
import cv2
import threading
import numpy as np
import qimage2ndarray
# import pyautogui
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5 import QtWidgets
from PyQt5 import QtGui
from PyQt5 import QtCore
from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtGui import *   # 사진 불러오기
import urllib.request       # 사진 불러오기
from PyQt5.QtCore import Qt, QSize
from matplotlib import pyplot as plt
   
form_class = uic.loadUiType("C:/photo_final/layout.ui")[0] # layout UI 불러오기

class layoutWindow(QMainWindow, form_class) : 
    global image
    global count
    global image1, image2, image3, image4
    count = 1

    def __init__(self) :
        super().__init__()
        self.setupUi(self)
        self.loadButton.clicked.connect(self.loadImage) #사진 불러오기 버튼
        self.saveButton.clicked.connect(self.save) #사진 저장 버튼
        self.homeButton.clicked.connect(self.home) # 메인화면으로 돌아가는 버튼

    def loadImage(self) :
        global count
        filename = QtWidgets.QFileDialog.getOpenFileName(self, "Open File", '', '사진(*.jpg; *jpeg; *png)') # 파일 이름 가져오기
        self.image = cv2.imread(filename[0])
        self.image = cv2.cvtColor(self.image, cv2.COLOR_BGR2RGB)
        self.image = cv2.resize(self.image, dsize=(200, 200), interpolation=cv2.INTER_AREA)
 
        if(count == 1) :
            self.image1 = self.image

        elif(count == 2) :
            self.image2 = self.image
            self.image = np.hstack((self.image1, self.image2))
            self.image2 = self.image

        elif(count == 3) :
            self.image3 = self.image
            whiteimg =  np.ones((200, 200, 3), dtype=np.uint8) * 255
            hs = np.hstack((self.image3, whiteimg))
            self.image = np.vstack((self.image2, hs))
        elif(count == 4) :
            self.image4 = self.image
            hs2 = np.hstack((self.image3, self.image4))
            self.image = np.vstack((self.image2, hs2))
            count = 0

        count+=1
        self.showImage(self.image)
        
    def showImage(self, img) : # 이미지 보여주기 함수(편집된 이미지도 볼 수 있음)
        qImg = qimage2ndarray.array2qimage(img, normalize=False)
        pixmap = QtGui.QPixmap.fromImage(qImg)
        self.label.setPixmap(pixmap)

    def save(self) :# 편집한 이미지 사진 저장
        self.image = cv2.cvtColor(self.image, cv2.COLOR_BGR2RGB)
        self.fname, _ = QFileDialog.getSaveFileName(self, 'Save Image Files', './', 'image files(*.jpg)' , options = QFileDialog.DontUseNativeDialog)
        cv2.imwrite(self.fname, self.image) 

    def home(self) :
        self.hide()
            
if __name__ == "__main__" :
    app = QApplication(sys.argv) 
    myWindow = layoutWindow() 
    myWindow.show()
    app.exec_()
