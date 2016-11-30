package Jweb;


import java.awt.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apple1
 */
public class JWeb extends javax.swing.JApplet{
    int num;
    
    public void init() {
        num = 255;
    }
    
    public void paint(Graphics screen) {
        Graphics2D screen2D = (Graphics2D)screen;
        screen2D.drawString("the square root of " + num + " is ", 5, 50);
    }
}
