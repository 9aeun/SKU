import sys
import cv2
import numpy as np
import threading
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5 import QtWidgets
from PyQt5 import QtGui
from PyQt5 import QtCore
from PyQt5.QtGui import QPixmap
   
form_class = uic.loadUiType("C:/photo_final/camera.ui")[0]
     
class cameraWindow(QMainWindow, form_class) : #카메라 윈도우
    global img #전역변수 이미지
    global cap #전역변수 캡쳐
    global LR #좌우반전
    global UD
    global W
    global B
    global O
    def __init__(self) :
        super().__init__()
        self.setupUi(self)

        self.originButton.clicked.connect(self.open) # 일반 카메라 버튼
        self.filmButton.clicked.connect(self.film) # 사진 촬영 버튼
        self.LRsyButton.clicked.connect(self.LRsy) # 좌우대칭 버튼
        self.UDsyButton.clicked.connect(self.UDsy) # 상하대칭 버튼
        self.waveButton.clicked.connect(self.wave) # 물결 버튼
        self.oButton.clicked.connect(self.olenz) #오목렌즈
        self.bolButton.clicked.connect(self.bollenz) #볼록렌즈 
        self.homeButton.clicked.connect(self.home) # main화면으로
    
    def showImage(self, img) : # 이미지를 매개변수로 받고, label에 보여주는 함수
        self.qImg = QtGui.QImage(img.data, img.shape[1], img.shape[0], QtGui.QImage.Format_RGB888) # 받은 이미지를 qImg로 변경
        self.pixmap = QtGui.QPixmap.fromImage(self.qImg) # qImage를 pixmap으로 변경
        self.label.setPixmap(self.pixmap) #label의 pixmap을 위의 pixmap으로 변경
        # self.label.resize(self.pixmap.width(), self.pixmap.height()) #label size를 pixmap의 크기로 변경

    def camera(self) : # 카메라를 여는 함수
        self.cap = cv2.VideoCapture(0)
        self.LR = 0
        self.UD = 0
        self.W = 0
        self.B = 0
        self.O = 0
        width = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        map_y, map_x = np.indices((height, width), dtype=np.float32) #map_x 는 [0~639](arange width) *480개, map_y는 [0~479] * 640개

        
        # 좌우 대칭 거울 좌표 연산
        mirrorh_x, mirrorh_y = map_x.copy(), map_y.copy()
        mirrorh_x[: , width//2:] = width - mirrorh_x[:, width//2:]
        print(mirrorh_x[:, width//2:])

        #상하 대칭 거울 좌표 연산
        mirrory_x, mirrory_y = map_x.copy(), map_y.copy()
        mirrory_y[height//2:, :] = height - mirrory_y[height//2:, :]

        # 물결 효과
        wave_x, wave_y = map_x.copy(), map_y.copy()
        wave_x = wave_x + 20*np.sin(map_y/20)
        wave_y = wave_y + 20*np.sin(map_x/20)

        # 볼록 렌즈
        lenz_x = 2*map_x / (width -1) -1
        lenz_y = 2*map_y / (height -1) -1
        magnitude, angle = cv2.cartToPolar(lenz_x, lenz_y)
        mx = magnitude.copy()
        my = magnitude.copy()
        mx[magnitude<1] = mx[magnitude<1] **2
        # 오목 렌즈
        my[magnitude<1] = my[magnitude<1] **0.5

        rx_x, rx_y = cv2.polarToCart(mx, angle)
        ry_x, ry_y = cv2.polarToCart(my, angle)

        rx_x = ((rx_x+1)*width-1)/2
        rx_y = ((rx_y+1)*height-1)/2
        ry_x = ((ry_x+1)*width-1)/2
        ry_y = ((ry_y+1)*height-1)/2


        while True:
            ret, image = self.cap.read()
            image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
            image = cv2.flip(image, 1) #좌우반전 카메라로

            if(self.LR==1):
                image = cv2.remap(image, mirrorh_x, mirrorh_y, cv2.INTER_LINEAR)
            
            if(self.UD==1):
                image = cv2.remap(image, mirrory_x, mirrory_y, cv2.INTER_LINEAR)

            if(self.W == 1) :
                image = cv2.remap(image, wave_x, wave_y, cv2.INTER_LINEAR, None, cv2.BORDER_REPLICATE)

            if(self.B == 1) :
                image = cv2.remap(image, rx_x, rx_y, cv2.INTER_LINEAR)

            if(self.O == 1) :
                image = cv2.remap(image, ry_x, ry_y, cv2.INTER_LINEAR)    

            self.img = image
            self.showImage(self.img)
            if not ret:
                print("cannot read frame.")
                break

    def open(self) :
        threading.Thread(target=self.camera).start()
        

    def film(self) : # 카메라 버튼을 누르면 사진이 찍히는 함수
        self.cap.release()
        self.showImage(self.img) # label의 이미지를 카메라에서 찍은 사진으로 바꿈
        self.img = cv2.cvtColor(self.img, cv2.COLOR_BGR2RGB)
        # 파일 저장하기
        self.fname, _ = QFileDialog.getSaveFileName(self, 'Save Image Files', './', 'image files(*.jpg)' , options = QFileDialog.DontUseNativeDialog)
        cv2.imwrite(self.fname, self.img)
        
    def LRsy(self) : 
        if(self.LR==0):
            self.LR += 1
        elif(self.LR==1):
            self.LR -= 1

    def UDsy(self) :
        if(self.UD ==0):
            self.UD = 1
        elif(self.UD ==1):
            self.UD = 0
    
    def wave(self) :
        if(self.W == 0):
            self.W = 1
        elif(self.W == 1):
            self.W = 0
    
    def bollenz(self) :
        if(self.B == 0):
            self.B = 1
        elif(self.B == 1):
            self.B = 0

    def olenz(self) :
        if(self.O == 0):
            self.O = 1
        elif(self.O == 1):
            self.O = 0

    def home(self) :
        self.hide()



               
if __name__ == "__main__" :
    app = QApplication(sys.argv) 
    myWindow = cameraWindow()
    myWindow.show()
    app.exec_()
