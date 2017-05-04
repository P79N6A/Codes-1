import java.util.ArrayList;
import java.util.Scanner;
/**
 * dist(v, u) > a[u]
 * Max(dist(v, u)) > a[u]时
 * u就应该被删除
 * @author GooZy
 */

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    private static int[] val = new int[MAXN];
    private static ArrayList<Integer>[] next = new ArrayList[MAXN];
    private static ArrayList<Integer>[] cost = new ArrayList[MAXN];
    private static int ans;
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            for (int i = 1; i <= n; ++i) {
                val[i] = in.nextInt();
                next[i] = new ArrayList<>();
                cost[i] = new ArrayList<>();
            }
            for (int i = 2; i <= n; ++i) {
                int v = in.nextInt(), w = in.nextInt();
                next[v].add(i);
                cost[v].add(w);
            }
            dfs(1, 0);
            System.out.println(n - ans);
        }
    }
    
    private static void dfs(int root, long dis) {
        ++ans;
        for (int i = 0; i < next[root].size(); ++i) {
            int v = next[root].get(i), w = cost[root].get(i);
            long save = dis;
            dis += w;
            if (dis < 0) dis = 0;
            if (dis <= val[v]) {
                dfs(v, dis);
            }
            dis = save;
        }
    }
}