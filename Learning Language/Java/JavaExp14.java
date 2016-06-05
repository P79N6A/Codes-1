public class JavaExp14 {
	public static void main(String[] args) {
		System.out.println("  I                   m(i)");
		for (int i = 10; i <= 100; i += 10) {
			System.out.printf("%3d               %.5f\n", i, m(i));
		}
	}
	
	public static double m(int x) {
		double ret = 0;
		for (double i = 1; i <= x; i += 2) {
			ret += 1 / (2 * i - 1) - 1 / (2 * i + 1);
		}
		return 4.0 * ret;
	}
}