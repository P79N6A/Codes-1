import java.util.*;

public class Main {
	
	private static int[] a = new int[20200];
	private static int[] b;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while (T-- != 0) {
			int n = in.nextInt(), m = in.nextInt();
			for (int i = 1; i <= n; ++i) {
				a[i] = in.nextInt();
			}
			while (m-- != 0) {
				int l = in.nextInt(), r = in.nextInt();
				b = Arrays.copyOfRange(a, l, r + 1);
				Arrays.sort(b);
				int ans = 0, sum = 0;
				for (int i : b) {
					sum += i;
					ans += sum;
				}
				System.out.println(ans);
			}
		}
		in.close();
	}
}