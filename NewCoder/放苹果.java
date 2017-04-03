import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static final int MAXN = 22;
    
    private static int[][] dp = new int[MAXN][MAXN];
    
    public static void main(String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);
        dp[0][0] = 1;
        while (in.hasNext()) {
            int m = in.nextInt(), n = in.nextInt();
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    dp[i][j] = dp[j][j];
                    if (j >= i) dp[i][j] = dp[i - 1][j] + dp[i][j - i];
                }
            }
            System.out.println(dp[n][m]);
        }
        in.close();
    }
}