import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.*;

public class Frame {
	public static void main(String[] args) {
		JFrame m = new JFrame("TEST");
		m.setSize(200, 200);
		m.setLocationRelativeTo(null);
		m.setLayout(new BorderLayout(5, 10));
		m.add(new JButton("sha?"), BorderLayout.SOUTH);
		m.add(new JLabel("first name"), BorderLayout.NORTH);
		JTextField fn = new JTextField(8);
		m.add(fn);
		m.add(new JLabel("last name"), BorderLayout.WEST);
		m.add(new JTextField(8), BorderLayout.WEST);
		m.add(new JLabel("hha name"), BorderLayout.EAST);
		m.add(new JTextField(8), BorderLayout.EAST);
		m.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		m.setVisible(true);
		
		System.out.println(fn.getText());
	}
}