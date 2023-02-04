package Final;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.image.*;

public class Origin extends JPanel {
   private Image img;
    public Origin(Image img){
       this.img = img;
       setSize(new Dimension(img.getWidth(null), img.getHeight(null)));
       setLayout(null);
    }
    
   public void paintComponent(Graphics g) {
      g.drawImage(img, 0, 0, null);
   }
}
