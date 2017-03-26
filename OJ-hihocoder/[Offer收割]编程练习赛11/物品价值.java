import java.util.*;

public class Main {
	
	private static int[] val = new int[1010];
	private static int[][] dp = new int[1010][1 << 11];
	private static int[] pro = new int[1010];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while (T-- != 0) {
			int n = in.nextInt(), m = in.nextInt();
			for (int i = 0; i <= n; ++i) {
				pro[i] = 0;
			}
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j < (1 << m); ++j) {
					dp[i][j] = -(int)3e8;
				}
			}
			dp[0][0] = 0;
			for (int i = 1; i <= n; ++i) {
				val[i] = in.nextInt();
				int k = in.nextInt();
				while (k-- != 0) {
					int x = in.nextInt() - 1;
					pro[i] |= 1 << x;
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < (1 << m); ++j) {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j ^ pro[i]] + val[i]);
				}
			}
			System.out.println(dp[n][(1 << m) - 1]);
		}
		in.close();
	}
}