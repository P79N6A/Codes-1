import javax.swing.JOptionPane;

public class TestJOptionPane {
	public static void main(String[] args) {
		double s[] = new double[3];
		String ss;
		for (int i = 0; i < s.length; ++i) {
			ss = JOptionPane.showInputDialog("输入第" + i + "个整数");
			s[i] = Double.parseDouble(ss);
			System.out.println(s[i]);
		}
	}
}