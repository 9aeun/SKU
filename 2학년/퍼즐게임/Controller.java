package Final;

public class Controller { //게임 control
	Model model = new Model();
	View view = new View();

	public void gameStart(){
		view.setSize(1000,700);
		view.setVisible(true);
		
		Sound test = new Sound();
		try {
			test.Music();
			Thread.sleep(213000);
		} catch (InterruptedException e) {				
			e.printStackTrace();
		}
	}
}
