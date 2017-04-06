import java.util.*;
/**
 * 找到端点不同的边,如果这两者成为根都无法满足条件,那么则
 * 无答案。因为其它节点为根肯定会包含以这两个端点为端点的
 * 边。然而不知道为什么JavaT了,明明就On的复杂度。
 * 最后用了不同边的个数,一定要等于某个点连接的不同边的个数
 * 才有答案。如果个数不等,那么子树肯定包含多出来的边,GG。
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = 110;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] u = new int[n], v = new int[n];
        int[] color = new int[n + 1];
        for (int i = 1; i < n; ++i) {
            int x = in.nextInt(), y = in.nextInt();
            u[i] = x;
            v[i] = y;
        }
        for (int i = 1; i <= n; ++i) {
            color[i] = in.nextInt();
        }
        int cnt = 0;
        int[] deg = new int[n + 1];
        for (int i = 1; i < n; ++i) {
            if (color[u[i]] == color[v[i]]) continue;
            ++cnt;
            ++deg[u[i]];
            ++deg[v[i]];
        }
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == cnt) {
                System.out.println("YES\n" + i);
                return;
            }
        }
        System.out.println("NO");
        in.close();
    }
}