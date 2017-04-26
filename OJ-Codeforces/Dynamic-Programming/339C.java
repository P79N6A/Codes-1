import java.util.Scanner;

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    
    private static boolean dfs(int p, int balance, int[] ans, String s) {
        if (p == ans.length) return true;
        for (int i = balance + 1; i <= 10; ++i) {
            if (s.charAt(i - 1) == '1' && ans[p - 1] != i) {
                ans[p] = i;
                if (dfs(p + 1, i - balance, ans, s)) return true;
            }
        }
        return false;
    }
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String s = in.next();
            int m = in.nextInt();
            int[] ans = new int[m + 1];
            if (dfs(1, 0, ans, s)) {
                System.out.println("YES");
                System.out.print(ans[1]);
                for (int i = 2; i <= m; ++i) {
                    System.out.print(" " + ans[i]);
                }
                System.out.println("");
            }
            else System.out.println("NO");
        }
    }
}