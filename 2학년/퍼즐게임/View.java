package Final;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.Random;
import javax.swing.*;

public class View extends JFrame{
	
	JDesktopPane xDesktop;
	LevelListener listener = new LevelListener();
	JInternalFrame fr3;
	JInternalFrame fr4;
	JInternalFrame fr5;
	Image image;
	public View() {
		super("퍼즐게임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());
		
		JPanel tool_bar = new JPanel(new BorderLayout());

		JPanel tool_pnl = new JPanel(new GridLayout(1,0));

		JButton btn;
		
		
		btn = new JButton("3×3");
		btn.setFont(new Font("굴림체",Font.BOLD,50));
		btn.setBackground(new Color(255,216,216));
		btn.addActionListener(listener);
		tool_pnl.add(btn);
		
		btn = new JButton("4×4");
		btn.setFont(new Font("굴림체",Font.BOLD,50));
		btn.setBackground(new Color(250,244,192));
		btn.addActionListener(listener);
		tool_pnl.add(btn);
		
		btn = new JButton("5×5");
		btn.setFont(new Font("굴림체",Font.BOLD,50));
		btn.setBackground(new Color(212,244,250));
		btn.addActionListener(listener);
		tool_pnl.add(btn);
		
		btn = new JButton("원본 사진");
		btn.setFont(new Font("굴림체",Font.BOLD,40));
		btn.setBackground(new Color(232,217,255));
		btn.addActionListener(listener);
		tool_pnl.add(btn);
		
		tool_bar.add(tool_pnl, BorderLayout.NORTH);
		cp.add(tool_bar, BorderLayout.NORTH);
		
		
		/* 데스크탑 패널 */
		
		
		xDesktop = new JDesktopPane();
		cp.add(xDesktop, BorderLayout.CENTER);
		
	}
	class LevelListener implements ActionListener{
		
		public void actionPerformed(ActionEvent e)
		{

			JButton b = (JButton)e.getSource();
			try {
				if(b.getText().equals("3×3"))
				{
					JInternalFrame fr3=new JInternalFrame("3×3", true, true, true, true);
					fr3= new MakeBtnView(3);
					fr3.setLayout(new GridLayout(3,3));
					xDesktop.add(fr3, 0);
					fr3.setVisible(true);
					fr3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				}
				
				else if(b.getText().equals("4×4"))
				{
					JInternalFrame fr4 =new JInternalFrame("4×4", true, true, true, true);
					fr4=new MakeBtnView(4);
					fr4.setLayout(new GridLayout(4,4));
					xDesktop.add(fr4, 0);
					fr4.setVisible(true);
					fr4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				}
				else if(b.getText().equals("5×5"))
				{
					JInternalFrame fr5 =new JInternalFrame("5×5", true, true, true, true);
					fr5=new MakeBtnView(5);
					fr5.setLayout(new GridLayout(5,5));
					xDesktop.add(fr5, 0);
					fr5.setVisible(true);
					fr5.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				}
				
				else if(b.getText().equals("원본 사진"))
				{
					JInternalFrame origin =new JInternalFrame("원본 사진", true, true, true, true);
					origin.setSize(200,200);
					Origin Origin = new Origin(new ImageIcon("image1.jpg").getImage());
					origin.add(Origin);
					xDesktop.add(origin, 0);
					origin.setVisible(true);
					origin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				}
			
			}catch(Exception ev) {}
		}
	}
}
