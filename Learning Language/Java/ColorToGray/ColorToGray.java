package colortogray;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class ColorToGray extends JFrame implements ChangeListener{
    
    ImagePanel org, cur;
    JSlider setGray;
    final String path = "src" + File.separator + "images" 
                    + File.separator + "photo.bmp";
    
    public ColorToGray() throws IOException {
        super("位图研究器");
        setSize(780, 570);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        
        org = new ImagePanel();
        org.setSize(360, 550);
        try {
            org.readImage(path);
        } catch (IOException e) {
            
        }
        add(org);
        
        setGray = new JSlider(JSlider.VERTICAL, 0, 100, 100);
        setGray.setMajorTickSpacing(50);
        setGray.setMinorTickSpacing(10);
        setGray.setPaintTicks(true);
        setGray.setPaintLabels(true);
        setGray.setBounds(365, 120, 50, 300);
        setGray.addChangeListener(this);
        add(setGray);
        
        cur = new ImagePanel();
        cur.setBounds(420, 0, 360, 550);
        try {
            cur.readImage(path);
        } catch (IOException e) {
            
        }
        cur.toGray(setGray.getValue());
        add(cur);
        
        setVisible(true);
    }
    
    public static void main(String[] args) throws IOException {
        ColorToGray colorToGray = new ColorToGray();
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        JSlider source = (JSlider) e.getSource();
        if (source.getValueIsAdjusting() == true) {
            //System.out.println(source.getValue());
            cur.toGray(source.getValue());
        }
    }
    
}