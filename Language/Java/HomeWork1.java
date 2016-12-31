import java.util.Scanner;

public class HomeWork1 {
	public static void main(String[] args) {
		System.out.println("请依次输入三角形的三个点的坐标:");
		Scanner scanner = new Scanner(System.in);
		double x[] = new double[3], y[] = new double[3], s[] = new double[4];
		int cnt = 0;
		s[3] = 0;
		for (int i = 0; i < 3; ++i) {
			x[i] = scanner.nextDouble();
			y[i] = scanner.nextDouble();
			for (int j = 0; j < i; ++j) {
				s[cnt++] = getdis(x[i], y[i], x[j], y[j]);
				s[3] += s[cnt - 1];
			}
		}
		s[3] /= 2;
		double ans = Math.sqrt(s[3] * (s[3] - s[0]) * (s[3] - s[1]) * (s[3] - s[2]));
		System.out.println("三角形面积为：" + ans);
	}
	
	public static double getdis(double x1, double y1, double x2, double y2) {
		double dx = x1 - x2;
		double dy = y1 - y2;
		return Math.sqrt(dx * dx + dy * dy);
	}
}