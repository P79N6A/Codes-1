import java.util.Scanner;
/**
 * 设状态dp[i][j],当前访问的为j和
 * 已经访问的列表i
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            long[] value = new long[n];
            long[][] mp = new long[n][n];
            for (int i = 0; i < n; ++i) {
                value[i] = in.nextInt();
            }
            for (int i = 0; i < q; ++i) {
                mp[in.nextInt() - 1][in.nextInt() - 1] = in.nextInt();
            }
            int up = 1 << n;
            long[][] dp = new long[up][n];
            for (int i = 0; i < n; ++i) {
                dp[1 << i][i] = value[i];
            }
            long ans = 0;
            for (int i = 1; i < up; ++i) {
                int cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if ((i & (1 << j)) != 0) ++cnt;
                }
                for (int j = 0; j < n; ++j) {
                    if ((i & (1 << j)) != 0) {
                        for (int k = 0; k < n; ++k) {
                            if ((i & (1 << k)) == 0) {
                                dp[i | (1 << k)][k] = 
                                        Math.max(dp[i | (1 << k)][k], 
                                                dp[i][j] + mp[j][k] + value[k]);
                            }
                        }
                        if (cnt == m) ans = Math.max(ans, dp[i][j]);
                    }
                }
            }
            System.out.println(ans);
        }
    }
}