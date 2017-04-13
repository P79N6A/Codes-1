import java.util.*;
/**
 * 数塔类型(MLE)
 * @author GooZy
 */
public class Main {
    
    private static final int MAXN = 110;
    
    private static int[][] a = new int[2][MAXN];
        
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int kase = 1; kase <= T; ++kase) {
            int n = in.nextInt(), cur = 0, last = 1;
            for (int i = 1; i <= n + 1; ++i) a[0][i] = 0;
            for (int i = 1; i <= n; ++i) {
                cur = 1 - cur;
                last = 1 - last;
                for (int j = 1; j <= i; ++j) {
                    a[cur][j] = in.nextInt();
                    if (j < i)
                        a[cur][j] += Math.max(a[last][j], a[last][j - 1]);
                    else a[cur][j] += a[last][j - 1];
                }
            }
            
            for (int i = n - 1; i > 0; --i) {
                cur = 1 - cur;
                last = 1 - last;
                for (int j = 1; j <= i; ++j) {
                    a[cur][j] = in.nextInt();
                    a[cur][j] += Math.max(a[last][j], a[last][j + 1]);
                }
            }
            
            System.out.println("Case " + kase + ": " + a[cur][1]);
        }
        in.close();
    }
}