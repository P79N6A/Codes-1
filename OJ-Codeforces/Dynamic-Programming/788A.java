import java.util.*;
/**
 * 处理之后的a[i]都为非负整数,分两种情况:
 * 以奇数开头,以偶数开头
 * 不管以什么开头,我们连续子序列的开头都是非负整数,
 * 所以所有情况都考虑到了。
 * @author GooZy
 */

public class Main {
    
    private static final long INF = (long)1e16;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextLong();
            if (i != 0) a[i - 1] = Math.abs(a[i - 1] - a[i]);
        }
        --n;
        long ans = -INF, sum = 0, sum2 = 0;
        int mul = 1;
        for (int i = 0; i < n; ++i, mul = -mul) {
            sum = Math.max(0, sum + mul * a[i]);
            sum2 = Math.max(0, sum2 + -mul * a[i]);
            ans = Math.max(Math.max(ans, sum), sum2);
        }
        System.out.println(ans);
        in.close();
    }
}