import java.io.*;
/**
 * 考虑将公式因式分解,只有2*5才能构成尾部0,
 * 所以最终结果其实只是取2和5中的最小值。分
 * 开DP即可。
 * 记得考虑有0值的情况,此时最大答案顶多为1
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    
    public static void main(String[] args) throws IOException {
        PrintWriter pr;
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            pr = new PrintWriter(new OutputStreamWriter(System.out));
            String s = in.readLine();
            int n = Integer.parseInt(s);
            int[][][] dp = new int[n + 1][n + 1][2];
            int[][][] org = new int[n + 1][n + 1][2];
            for (int i = 2; i <= n; ++i) {
                for (int k = 0; k < 2; ++k)
                    dp[0][i][k] = dp[i][0][k] = (int)6e4;
            }
            int sx = -1, sy = -1;
            for (int i = 1; i <= n; ++i) {
                String[] ss = in.readLine().split(" ");
                for (int j = 1; j <= n; ++j) {
                    int x = Integer.parseInt(ss[j - 1]);
                    if (x == 0) {
                        x = 1;
                        sx = i;
                        sy = j;
                    }
                    while (x % 2 == 0) {
                        x /= 2;
                        ++dp[i][j][0];
                    }
                    while (x % 5 == 0) {
                        x /= 5;
                        ++dp[i][j][1];
                    }
                    org[i][j][0] = dp[i][j][0];
                    org[i][j][1] = dp[i][j][1];
                    for (int k = 0; k < 2; ++k) {
                        dp[i][j][k] += Math.min(dp[i - 1][j][k], dp[i][j - 1][k]);
                    }
                }
            }
            int k = (dp[n][n][0] < dp[n][n][1] ? 0 : 1);
            if (dp[n][n][k] > 1 && sx != -1) {
                pr.println(1);
                for (int i = 1; i < sx; ++i) pr.print("D");
                for (int j = 1; j < sy; ++j) pr.print("R");
                for (int i = sx; i < n; ++i) pr.print("D");
                for (int j = sy; j < n; ++j) pr.print("R");
                pr.println();
                pr.close();
                return;
            }
            pr.println(dp[n][n][k]);
            String ans = "";
            int i = n, j = n;
            while (true) {
                // System.out.println(i + " : " + j);
                if (i == 1 && j == 1) break;
                if (i != 1 && dp[i - 1][j][k] + org[i][j][k] == dp[i][j][k]) {
                    ans += "D";
                    --i;
                }
                else {
                    ans += "R";
                    --j;
                }
            }
            for (int p = ans.length() - 1; p >= 0; --p) {
                pr.print(ans.charAt(p));
            }
            pr.println();
        }
        pr.close();
    }
}