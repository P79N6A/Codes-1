import java.awt.*;
import java.awt.image.*;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.*;


public class Main extends JFrame {
	
	public Main() throws IOException {
        super("ok");
        setBounds(100, 100, 800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(1, 3));
        
        ImagePanel imagePanel = new ImagePanel();
		for (int i = 0; i < 4; ++i) {
			String path = "C:\\Users\\apple\\Desktop\\ques\\ques" + (i + 1) + ".PNG";
			imagePanel.readImage(path, i);
		}
		imagePanel.work();
		
        add(imagePanel);
        setVisible(true);
    }
	public static void main(String[] args) throws IOException {
		new Main();
	}
}

class ImagePanel extends JPanel {

    int width, height;
    Color bufferImage[][][] = new Color[4][][], result[][];
    
    boolean inRange(int x) {
    	x = Math.abs(x);
    	return 5 <= x && x <= 20;
    }
    
    public void readImage(String path, int index) throws IOException {
        File file = new File(path);
        BufferedImage buff = ImageIO.read(file);
        width = buff.getWidth();
        height = buff.getHeight();
        bufferImage[index] = new Color[width][height];
        result = new Color[width][height];
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                 bufferImage[index][i][j] = new Color(buff.getRGB(i, j));
            }
        }
        //add(new JLabel(new ImageIcon(photo)));
    }
    
    public void work() {
    	for (int i = 0; i < width; ++i) {
    		for (int j = 0; j < height; ++j) {
    			Color temp = bufferImage[0][i][j];
    			int difr = temp.getRed() - bufferImage[2][i][j].getRed();
    			int difg = temp.getGreen() - bufferImage[2][i][j].getGreen();
    			int difb = temp.getBlue() - bufferImage[2][i][j].getBlue();
    			
    			int cnt = 0;
    			for (int k = 1; k < 4; ++k) {
    				if (k == 2) continue;
    				if (temp.equals(bufferImage[k][i][j])) {
    					++cnt;
    				}
    			}
    			
    			if (inRange(difr) && inRange(difg) && inRange(difb)) ++cnt;
    			
    			if (cnt == 3) {
    				result[i][j] = new Color(255, 255, 255);
    			}
    			else {
    				result[i][j] = new Color(0, 0, 0);
    			}
    		}
    	}
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                g.setColor(result[i][j]);
                g.drawLine(i, j, i, j);
            }
        }
    }

}

