import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static final int MAXN = 100010;
    private static long[] a = new long[MAXN];
    
    static class Node {
        int[] nxt = new int[2];
        long val;
        public Node() {
            nxt[0] = nxt[1] = -1;
        }
    }
    
    private static int pos;
    private static Node[] trie = new Node[MAXN * 20];
    
    private static int extend() {
        ++pos;
        trie[pos] = new Node();
        return pos;
    }
    
    private static void build(long x) {
        int p = 0;
        for (int i = 19; i >= 0; --i) {
            int flag = (x & (1 << i)) == 0 ? 0 : 1;
            if (trie[p].nxt[flag] == -1) {
                trie[p].nxt[flag] = extend();
            }
            p = trie[p].nxt[flag];
        }
        trie[p].val = x;
    }
    
    private static long query(long x) {
        int p = 0;
        for (int i = 19; i >= 0; --i) {
            if (trie[p].nxt[1] != -1) p = trie[p].nxt[1];
            else p = trie[p].nxt[0];
        }
        return x * trie[p].val * (x & trie[p].val);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- != 0) {
            int n = in.nextInt();
            pos = -1;
            extend();
            long ans = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextLong();
            }
            Arrays.sort(a, 0, n);
            for (int i = 0; i < n; ++i) {
                if (i != 0) ans = Math.max(ans, query(a[i]));
                build(a[i]);
            }
            System.out.println(ans);
        }
        in.close();
    }
}