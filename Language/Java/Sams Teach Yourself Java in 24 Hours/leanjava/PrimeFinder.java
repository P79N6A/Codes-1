/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

import java.awt.BorderLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author apple1
 */
public class PrimeFinder extends JFrame implements Runnable, ActionListener{
    Thread go;
    JLabel howManyLabel;
    JTextField howMany;
    JButton display;
    JTextArea primes;

    public PrimeFinder() {
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        
        howManyLabel = new JLabel("Quantity: ");
        howMany = new JTextField("400", 10);
        display = new JButton("Display primes");
        primes = new JTextArea(8, 40);
        
        display.addActionListener(this);
        JPanel topPanel = new JPanel();
        topPanel.add(howManyLabel);
        topPanel.add(howMany);
        topPanel.add(display);
        add(topPanel, BorderLayout.NORTH);
        
        primes.setLineWrap(true);
        JScrollPane textPane = new JScrollPane(primes);
        add(textPane, BorderLayout.CENTER);
        
        setVisible(true);
    }
    
    public void actionPerformed(ActionEvent event) {
        display.setEnabled(false);
        if (go == null) {
            go = new Thread(this);
            go.start();
        }
    }
    
    public void run() {
        int quantity = Integer.parseInt(howMany.getText());
        int numPrimes = 0, candidate = 2;
        primes.append("First " + quantity + " primes:");
        while (numPrimes < quantity) {
            if (isprime(candidate)) {
                primes.append(candidate + " ");
            }
            ++candidate;
        }
    }
    
    public boolean isprime(int x) {
        for (int i = 2; i <= (int)Math.sqrt(x); ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
}
