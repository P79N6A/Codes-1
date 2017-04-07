import java.util.*;
/**
 * 最多移动三行,所以暴力枚举三行即可
 * dp[i][j]:第i行变成状态j需要的最少代价。
 * @author GooZy
 */

public class Main {
    
    private static final int INF = (int)1e8;
    
    private static int setFlag(char c) {
        if (Character.isDigit(c)) return 0;
        else if (Character.isLowerCase(c)) return 1;
        return 2;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        in.nextLine();
        int[][] dp = new int[n][3];
        int[][] mp = new int[n][m];
        for (int i = 0; i < n; ++i) {
            char[] s = in.next().toCharArray();
            for (int j = 0; j < m; ++j) {
                mp[i][j] = setFlag(s[j]);
            }
        }
        for (int i = 0; i < n; ++i) Arrays.fill(dp[i], INF);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][mp[i][j]] = Math.min(Math.min(dp[i][mp[i][j]], j), m - j);
            }
        }
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || k == i) continue;
                    ans = Math.min(ans, dp[i][0] + dp[j][1] + dp[k][2]);
                }
            }
        }
        System.out.println(ans);
        in.close();
    }
}