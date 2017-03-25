import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double ans = 0;
		int n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			double x = in.nextDouble(), p = in.nextDouble();
			ans += x * p;
		}
		System.out.printf("%.3f\n", ans / 100);
		in.close();
	}
}