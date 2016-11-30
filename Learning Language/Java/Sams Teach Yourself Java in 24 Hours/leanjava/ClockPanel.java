/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

import java.util.*;
import javax.swing.*;

/**
 *
 * @author apple1
 */
public class ClockPanel extends JPanel{
    public ClockPanel() {
        super();
        JLabel time = new JLabel("time: ");
        JLabel current = new JLabel(getTime());
        add(time);
        add(current);
    }
    
    final String getTime() {
        String time = "";
        Calendar now = Calendar.getInstance();
        int hour = now.get(Calendar.HOUR);
        int minu = now.get(Calendar.MINUTE);
        return time = hour + ":" + minu;
    }
}
