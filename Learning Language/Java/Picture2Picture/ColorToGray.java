package colortogray;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;

public class ColorToGray extends JFrame implements ActionListener {
    
    ImagePanel org, cur;
    JPanel p1, p2, p3;
    JButton open1, open2, begin;
    JSlider setGray;
    
    public ColorToGray() throws IOException {
        super("图片转换器");
        setBounds(100, 100, 800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(1, 3));
        
        p1 = new JPanel(new BorderLayout(6, 8));
        org = new ImagePanel();
        p1.add(org, BorderLayout.CENTER);
        open1 = new JButton("打开图像");
        open1.addActionListener(this);
        p1.add(open1, BorderLayout.SOUTH);
        
        p2 = new JPanel(new BorderLayout(6, 8));
        p2.add(new JLabel("               帧数:"),BorderLayout.NORTH);
        setGray = new JSlider(JSlider.VERTICAL, 0, 30, 30);
        setGray.setMajorTickSpacing(10);
        setGray.setMinorTickSpacing(1);
        setGray.setPaintTicks(true);
        setGray.setPaintLabels(true);
        p2.add(setGray, BorderLayout.CENTER);
        begin = new JButton("开始转换");
        begin.addActionListener(this);
        p2.add(begin, BorderLayout.SOUTH);
        
        p3 = new JPanel(new BorderLayout(6, 8));
        cur = new ImagePanel();
        p3.add(cur, BorderLayout.CENTER);
        open2 = new JButton("打开图像");
        open2.addActionListener(this);
        p3.add(open2, BorderLayout.SOUTH);
        
        add(p1);
        add(p2);
        add(p3);
        setVisible(true);
    }
    
    public static void main(String[] args) throws IOException {
        ColorToGray colorToGray = new ColorToGray();
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        Object source = event.getSource(); // 返回触发事件的控件名
        // getActionCommand()返回控件上写的文字
        if (source == open1) {
            JFileChooser jfc = new JFileChooser();
            if(jfc.showOpenDialog(this)==JFileChooser.APPROVE_OPTION ){
                try {
                    org.readImage(jfc.getSelectedFile().getAbsolutePath());
                    org.repaint();
                } catch (IOException ex) {
                    Logger.getLogger(ColorToGray.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        } else if (source == open2) {
            JFileChooser jfc = new JFileChooser();
            if(jfc.showOpenDialog(this)==JFileChooser.APPROVE_OPTION ){
                try {
                    cur.readImage(jfc.getSelectedFile().getAbsolutePath());
                    cur.repaint();
                } catch (IOException ex) {
                    Logger.getLogger(ColorToGray.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        } else {
            int width = org.width, height = org.height;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < height; ++j) {
                    org.target[i][j] = cur.orgRGB[i][j];
//                    System.out.println(org.orgRGB[i][j] + "--->" + org.target[i][j]);
                }
            }
            try {
                org.toOther(setGray.getValue());
            } catch (InterruptedException ex) {
                Logger.getLogger(ColorToGray.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}

