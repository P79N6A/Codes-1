/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

import java.awt.BorderLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 *
 * @author apple1
 */
public class KeyViewer extends JFrame implements KeyListener{
    JTextField jt = new JTextField(10);
    JLabel mess = new JLabel("Plz enter any key to test.");
    
    public KeyViewer() {
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        jt.addKeyListener(this);
        add(mess, BorderLayout.NORTH);
        add(jt, BorderLayout.CENTER);
        //jt.setEditable(false);
        setVisible(true);
    }

    @Override
    public void keyTyped(KeyEvent e) {
        char key = e.getKeyChar();
        mess.setText("the key you enter is " + key);
    }

    @Override
    public void keyPressed(KeyEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyReleased(KeyEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
