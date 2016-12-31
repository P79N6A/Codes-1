/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package colortogray;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

/**
 *
 * @author apple1
 */
public class ImagePanel extends JPanel {
    BufferedImage photo;
    int width, height;
    // 修改后的图片
    // 原图
    // 目标图片
    Color bufferImage[][], orgRGB[][], target[][];
    
    public void readImage(String path) throws IOException {
        File file = new File(path);
        BufferedImage buff = ImageIO.read(file);
        width = buff.getWidth();
        height = buff.getHeight();
        bufferImage = new Color[width][height];
        orgRGB = new Color[width][height];
        target = new Color[width][height];
        System.out.printf("%d X %d\n", width, height);
        
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                orgRGB[i][j] = bufferImage[i][j] = new Color(buff.getRGB(i, j));
            }
        }
        //add(new JLabel(new ImageIcon(photo)));
    }
    
    public void toOther(int base) throws InterruptedException {
        new Thread(new Runnable() {
            @Override
            public void run() {
                //一步一步生成图片,用step占用base的百分比来确定步长
                for (int step = 1; step <= base; ++step) {
                    float mul = (float)step / base;
                   
                    for (int i = 0; i < width; ++i) {
                        for (int j = 0; j < height; ++j) {
                            int red = orgRGB[i][j].getRed();
                            int red2 = target[i][j].getRed();
                            int green = orgRGB[i][j].getGreen();
                            int green2 = target[i][j].getGreen();
                            int blue = orgRGB[i][j].getBlue();
                            int blue2 = target[i][j].getBlue();
                            try {
                            bufferImage[i][j] = new Color(red + (int)((red2 - red) * mul), 
                                                        green + (int)((green2 - green) * mul), 
                                                        blue + (int)((blue2 - blue) * mul));
                            } catch(IllegalArgumentException e) {
                                System.out.println("Out of Range");
                            }
                        }
                    }
                    System.out.println(mul);
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(ImagePanel.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    repaint();
                }
            }
        }).start();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                g.setColor(bufferImage[i][j]);
                g.drawLine(i, j, i, j);
            }
        }
    }

}
