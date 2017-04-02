import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static final int MAXN = 110;
    
    private static char[][] mp = new char[MAXN][];
    private static int[] par;
    private static int n, m;
    
    private static int get(int x, int y, int add) {
        return x * m + y + add;
    }
    
    private static int find(int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    
    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            par[x] = y;
        }
    }
    
    static class Node {
        int l, r, u, d;
        public Node(int u, int d, int l, int r) {
            this.u = u;
            this.d = d;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        Node[][] node = new Node[n][m];
        in.nextLine();
        int base = 0;
        for (int i = 0; i < n; ++i) {
            mp[i] = in.nextLine().toCharArray();
            for (int j = 0; j < m; ++j) {
                switch (mp[i][j]) {
                    case ' ':
                        node[i][j] = new Node(base, base + 1, base, base + 1);
                        break;
                    case '\\':
                        node[i][j] = new Node(base + 1, base, base, base + 1);
                        break;
                    default:
                        node[i][j] = new Node(base, base + 1, base, base + 1);
                        break;
                }
                base += 2;
            }
        }
        
        par = new int[base];
        for (int i = 0; i < base; ++i) {
            par[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i != 0) union(node[i][j].u, node[i - 1][j].d);
                if (j != 0) union(node[i][j].l, node[i][j - 1].r);
                if (mp[i][j] == ' ') union(node[i][j].l, node[i][j].r);
            }
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < base; ++i) {
            set.add(find(i));
        }
        System.out.println(set.size());
        in.close();
    }
}