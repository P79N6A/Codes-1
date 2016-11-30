/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.HeadlessException;
import java.awt.RenderingHints;
import java.awt.geom.Arc2D;
import java.awt.geom.Rectangle2D;
import javax.swing.*;

/**
 *
 * @author apple1
 */
public class Graphic2D extends JFrame{

    public Graphic2D() throws HeadlessException {
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g); //To change body of generated methods, choose Tools | Templates.
        Graphics2D cur = (Graphics2D) g;
        Font ft = new Font("yao", Font.BOLD, 30);
        cur.setColor(Color.white);
        cur.fillRect(0, 0, 400, 400);
        cur.setColor(Color.black);
        cur.setFont(ft);
        cur.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        //cur.drawString("Hello world! 1 2 3 4 5 6 7 !", 100, 100);
        Arc2D.Float smile = new Arc2D.Float(0, 0, 65F, 75F,
30F, -60F, Arc2D.Float.OPEN);
        
        cur.fill(smile);
    }
    
}
