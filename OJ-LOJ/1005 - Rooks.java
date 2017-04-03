import java.util.*;

public class Main {
    
    private static final long INF = (int)1e8;
    private static final int MAXN = 32;
    
    private static long[][] dp = new long[MAXN][MAXN];
    private static long[] f = new long[MAXN];
    
    public static void main(String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);
        f[0] = 1;
        for (int i = 1; i <= 30; ++i) {
            f[i] = f[i - 1] * i;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) dp[i][j] = 1;
                else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
            }
        }
        int T = in.nextInt();
        for (int kase = 1; kase <= T; ++kase) {
            int n = in.nextInt(), k = in.nextInt();
            System.out.println("Case " + kase + ": " + dp[n][k] * dp[n][k] * f[k]);
        }
        in.close();
    }
}