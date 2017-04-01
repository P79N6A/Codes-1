import java.util.*;

public class Main {
    
    private static final int MAXN = 1011;
    private static int[] pre = new int[MAXN], mid = new int[MAXN];
    
    static class Node {
        Node left;
        Node right;
        int val;
        public Node(int val) {
            this.val = val;
        }
    }
    
    private static Node build(int pl, int pr, int ml, int mr) {
        if (pl > pr) return null;
        Node ret = new Node(pre[pl]);
        for (int i = ml; i <= mr; ++i) {
            if (mid[i] == pre[pl]) {
                ret.left = build(pl + 1, pl + i - ml, ml, i - 1);
                ret.right = build(pl + i - ml + 1, pr, i + 1, mr);
            }
        }
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            pre[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            mid[i] = in.nextInt();
        }
        Node root = build(0, n - 1, 0, n - 1);
        int[] ans = new int[n];
        int base = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (queue.size() != 0) {
            Node cur = queue.poll();
            ans[base++] = cur.val;
            if (cur.left != null) queue.add(cur.left);
            if (cur.right != null) queue.add(cur.right);
        }
        for (int i = 0; i < n; ++i) {
            System.out.print(ans[i]);
            System.out.print(i == n - 1 ? "\n" : " ");
        }
        in.close();
    }
}