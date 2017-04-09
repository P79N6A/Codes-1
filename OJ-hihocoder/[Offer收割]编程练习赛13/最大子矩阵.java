import java.util.*;

public class Main {
    
    private static final long INF = (long)1e16;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int[][] sum = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) sum[i][0] = 0;
        for (int i = 0; i <= m; ++i) sum[0][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = in.nextInt();
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                //System.out.println(sum[i][j]);
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int x = 0; x < i; ++x) {
                    for (int y = 0; y < j; ++y) {
                        int temp = sum[i][j] + sum[x][y] - sum[i][y] - sum[x][j];
                        //System.out.println(temp);
                        int num = (j - y) * (i - x);
                        if (temp <= k && num > ans) ans = num;
                    }
                }
            }
        }
        System.out.println(ans);
        in.close();
    }
}