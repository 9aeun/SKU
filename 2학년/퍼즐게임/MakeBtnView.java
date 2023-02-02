package Final;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.Random;
import javax.swing.*;
import javax.sound.sampled.*;
import java.io.File;

public class MakeBtnView extends JInternalFrame implements ActionListener{
	Model model = new Model();
	int[] picture;
	int row=1;
	int col=1;
	int n = row*col-1;
	long start = System.currentTimeMillis();
	JButton[] btn;
	Image image;
	BufferedImage img[];
	long end;
	
	public MakeBtnView(int level) {
		
		this.row = level;
		this.col=level;
		this.n=row*col-1;
		//이미지 분할하기
		MediaTracker tracker = new MediaTracker(this);

		image = Toolkit.getDefaultToolkit().getImage("image1.jpg");
		image=image.getScaledInstance(400, 400, Image.SCALE_SMOOTH);

		tracker.addImage(image, 0);
		try {
			tracker.waitForAll();
		} catch (InterruptedException e) {;}
		
		int width = image.getWidth(this)/col;
		int height = image.getHeight(this)/row;
		setSize(new Dimension(width*col,height*row));
		
		//이미지를 잘라서 이미지 버퍼에 넣기
		img =new BufferedImage[row*col];
		int c=0;
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				img[c] = new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);
				Graphics g = img[c].getGraphics();
				g.drawImage(image,
					0, 0,  width, height, 
		            j*width, i*height,(j+1)*width, (i+1)*height,this);
				c++;
			}
			
		}
		
		 // 버튼 만들기
	      picture = new int[row * col];
	      btn = new JButton[row * col];

	      for (int i = 0; i < row * col; i++) {
	         btn[i] = new JButton();
	         btn[i].addActionListener(this);
	         btn[i].addActionListener(new ActionListener() {

	        	 //버튼 누를 때마다 효과음
	            @Override
	            public void actionPerformed(ActionEvent e) {
	               File bgm;
	               AudioInputStream stream;
	               AudioFormat format;
	               DataLine.Info info;

	               bgm = new File("MP_Blop.wav");
	               Clip clip;
	               try {
	                  stream = AudioSystem.getAudioInputStream(bgm);
	                  format = stream.getFormat();
	                  info = new DataLine.Info(Clip.class, format);
	                  clip = (Clip) AudioSystem.getLine(info);
	                  clip.open(stream);
	                  clip.start();

	               } catch (Exception e2) {
	                  System.out.println("err : " + e2);
	               }

	            }
	         });
	         add(btn[i]);
	      }

	      shuffle();
	      

	}
	
	private void shuffle() 
	{
		Random rnd = new Random();
		for(int i=0;i<row*col-1;i++) {
			int temp=0;
			do{
				temp = rnd.nextInt(row*col);
			}while(picture[temp]!=0);
			
			picture[temp] = i;
			
			if(picture[temp]==0 && picture[row*col-1]!=row*col-1)
			{
				picture[temp]=picture[row*col-1];
				picture[row*col-1]=row*col-1;
			}
			
	    }
		
		picture[row*col-1]=row*col-1;
		//배열 값을 이미지를 선택해서 버튼에 부여
		for(int i=0;i<row*col-1;i++)
		{
			btn[i].setIcon(new ImageIcon(img[picture[i]]));
		}
	}

	public void actionPerformed(ActionEvent e) {
		
		for(int i=0; i<row*col; i++)
		{
			if(e.getSource()==btn[i])
			{
				if(i==(n-1)||i==(n+1)||i==(n-row)||i==(n+row))
				{
					btn[i].setIcon(new ImageIcon());
					btn[n].setIcon(new ImageIcon(img[picture[i]]));
					//버튼에 담겨있는 번호 swap
					int t = picture[n];
					picture[n] = picture[i];
					picture[i] = t;
					//n에 i 저장
					n=i;
				}
				
			}
		}
		
		if (model.isEnd(picture))
	      {
	          long end = System.currentTimeMillis();
	          int time=(int)(end-start)/1000;
	          int sec = (int)(end-start)/1000%60;
	          int min = (int)(end-start)/1000/60%60;
	          model.setScore(time);
	          JOptionPane.showMessageDialog(this, "Success!! \n" + min+ "분" +sec+ "초" + "\n 당신의 점수는 999점 만점에 " + model.Score + "입니다.");
	          System.exit(1);

	      }
	}
}
