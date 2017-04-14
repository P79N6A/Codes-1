import java.util.ArrayList;
import java.util.Scanner;
/**
 * dp[i]:使用到i作为gmd的最长有多长
 * 所以我们可以把i的所有素数因子存下来,
 * 最后更新成最新值。
 * @author GooZy
 */
public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    private static int[] dp = new int[MAXN];
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            int ans = 1;
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                ArrayList<Integer> al = new ArrayList<>();
                int temp = x;
                for (int j = 2; j * j <= temp; ++j) {
                    if (temp % j == 0) {
                        dp[x] = Math.max(dp[x], dp[j] + 1);
                        al.add(j);
                        while (temp % j == 0) temp /= j;
                    }
                }
                if (temp != 1) {
                    dp[x] = Math.max(dp[x], dp[temp] + 1);
                    al.add(temp);
                }
                for (int j : al) {
                    dp[j] = dp[x];
                }
                ans = Math.max(ans, dp[x]);
            }
            System.out.println(ans);
        }
    }
}