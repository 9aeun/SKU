from PyQt5 import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import*
from PyQt5 import uic
import sys
from camera import cameraWindow
from photo import photoWindow
from layout import layoutWindow
   
form_class = uic.loadUiType("C:/photo_final/main.ui")[0] 

class mainWindow(QMainWindow, form_class) : # main 화면이 보이는 window class

    def __init__(self) : # 초기화 메서드
        global w
        super().__init__()
        self.setupUi(self) #UI파일을 파이썬 코드에서 로드
   
        self.cameraButton.clicked.connect(self.showCamera) # 사진 찍기 버튼 
        self.photoButton.clicked.connect(self.showPhoto)   # 사진 편집 버튼
        self.layoutButton.clicked.connect(self.showLayout) # 레이아웃 버튼

    def showCamera(self) : # 카메라 버튼 눌렀을 때, camera.py가 새창으로 나오도록 하는 함수
        self.w = cameraWindow()    #cameraWindow를 현재 윈도우로 설정
        self.w.show() #현재 윈도우 보이게 하기

    def showPhoto(self) : # 사진 버튼 눌렀을 때, photo.py가 새창으로 나오도록 하는 함수
        self.w = photoWindow() 
        self.w.show()


    def showLayout(self) : # 레이아웃 버튼 눌렀을 때, layout.py가 새창으로 나오도록(메인 창이 없어지지 않음)
        self.w = layoutWindow()
        self.w.show()

if __name__ == "__main__" : #ui파일 열기
    app = QApplication(sys.argv) 
    myWindow = mainWindow() 
    myWindow.show()
    app.exec_()
