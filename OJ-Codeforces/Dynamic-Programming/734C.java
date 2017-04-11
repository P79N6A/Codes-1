import java.util.*;
/**
 * 考虑从费用大的type1到费用小的type1
 * 这时剩余价值也随之增大,所以可以想到
 * 用滑动窗口来增加type2的使用,每次保留
 * 最大值。注意考虑不使用type1的情况
 * @author GooZy
 */

public class Main {
    
    private static final long INF = (long)1e16;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        int m = in.nextInt(), k = in.nextInt();
        A[] a = new A[m + 1];
        B[] b = new B[k];
        long x = in.nextLong(), s = in.nextLong();
        for (int i = 0; i < m; ++i) {
            a[i] = new A();
            a[i].a = in.nextLong();
        }
        for (int i = 0; i < m; ++i) {
            a[i].b = in.nextLong();
        }
        for (int i = 0; i < k; ++i) {
            b[i] = new B();
            b[i].c = in.nextLong();
        }
        for (int i = 0; i < k; ++i) {
            b[i].d = in.nextLong();
        }
        a[m] = new A();
        a[m].a = x;
        a[m].b = 0;
        Arrays.sort(a);
        int j = 0;
        long mx = 0, ans = x * n;
        for (int i = 0; i <= m; ++i) {
            if (a[i].b > s) continue;
            long left = s - a[i].b;
            while (j < k && b[j].d <= left) {
                mx = Math.max(mx, b[j].c);
                ++j;
            }
            ans = Math.min(ans, a[i].a * (n - mx));
        }
        System.out.println(ans);
        in.close();
    }
}

class A implements Comparable<A> {
    long a, b;
    @Override
    public int compareTo(A o) {
        return (int)(o.b - b);
    }
}

class B {
    long c, d;
}