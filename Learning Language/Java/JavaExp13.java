public class JavaExp13 {
	public static void main(String[] args) {
		double ans = 0;
		for (double i = 3; i <= 99; i += 2) {
			ans += (i - 2) / i;
		}
		System.out.println(ans);
	}
}