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
import javax.swing.JPanel;

/**
 *
 * @author apple1
 */
public class ImagePanel extends JPanel {
    BufferedImage photo;
    int width, height;
    Color bufferImage[][], orgRGB[][];
    
    public void readImage(String path) throws IOException {
        FileInputStream file = new FileInputStream(path);
        BufferedInputStream buff = new BufferedInputStream(file);
        // 14字节位图头信息 + 4字节位图信息头占用大小
        buff.skip(18);
        byte w[] = new byte[4], h[] = new byte[4];
        buff.read(w);
        buff.read(h);
        width = byteToInt(w);
        height = byteToInt(h);
        System.out.printf("%d X %d\n", width, height);
        // 计算每四字节一起,剩余多少字节需要跳过
        int left = (4 - width * 3 % 4) % 4;
        bufferImage = new Color[width][height];
        orgRGB = new Color[width][height];
        buff.skip(28); // 丢弃剩余的
        
        // 从左下角到右上角,行先
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int blue = buff.read();
                int green = buff.read();
                int red = buff.read();
                int ni = height - i - 1, nj = j;
                orgRGB[nj][ni] = bufferImage[nj][ni] = new Color(red, green, blue);
            }
            if (left != 0) {
                buff.skip(left);
            }
        }
        //add(new JLabel(new ImageIcon(photo)));
    }
    
    // 注意是小端存储
    public int byteToInt(byte a[]) {
        return (a[3] << 24) | (a[2] << 16) | (a[1] << 8) | a[0];
    }
    
    public void toGray(int base) {
        float mul = (float)base / 100;
        //System.out.println(mul);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int red = orgRGB[i][j].getRed();
                int green = orgRGB[i][j].getGreen();
                int blue = orgRGB[i][j].getBlue();
                int gray = (int)((red * 0.3f + green * 0.59f + blue * 0.11f) * mul);
                bufferImage[i][j] = new Color(gray, gray, gray);
            }
        }
        repaint();
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
