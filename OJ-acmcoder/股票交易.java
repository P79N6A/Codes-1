import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            a[i] = in.nextInt();
        }
        int k = in.nextInt();
        int buy = -1000000000;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = Math.max(a[i] + buy, dp[i - 1]);
            if (i > k) buy = Math.max(buy, dp[i - k - 1] - a[i]);
            else buy = Math.max(buy, -a[i]);
        }
        System.out.println(dp[n]);
        in.close();
    }
}
/**
 * 8
 * 1 2 3 5 6 2 3 7
 * 2
 * 8
 */