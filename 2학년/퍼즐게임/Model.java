package Final;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.Arrays;

import javax.swing.*;

public class Model {
	public int level; //게임의 level을 고르는 변수(3,4,5 중 하나)
	public JButton[] btn; 
	public Image image; //게임에 사용 할 이미지를 저장하는 이미지 변수
	public BufferedImage img[]; //분할 한 이미지를 저장하는 이미지버퍼
	public int[] picture;
	public int count; //실행 횟수를 세기 위한 변수
	public int time; //시간을 재기 위한 변수
	public int Score; //점수 변수
	
	public int row = level;
	public int col = level;	
	
	public void setLevel(int level) {
		this.level=level;
	}
	
	public void setBtn(JButton[] btn) {
		this.btn=btn;
	}

	public boolean isEnd(int[] picture) {
		boolean endGame=true;
		  
		for(int i=0;i<picture.length;i++){
		   if(i!=picture[i]){
		    endGame = false;
		   }
		}
		  
		return endGame;
	}
	
	public void setScore(int time) { //다른 곳에서 cScore을 사용할 때 호출하는 함수
		if(time<999)
			this.Score=999-time;
		else
			this.Score=0;
	}

	public void setTime(int time) { 
		this.time=time;
	}

}
