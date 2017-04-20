import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] a = in.next().toCharArray();
		char[] b = in.next().toCharArray();
		int n = a.length, m = b.length;
		int[][] dp = new int[n + 1][m + 1];
		for (int i = 1; i <= n; ++i) dp[i][0] = i;
		for (int i = 1; i <= m; ++i) dp[0][i] = i;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
				}
			}
		}
		System.out.println(dp[n][m]);
	}
	
}