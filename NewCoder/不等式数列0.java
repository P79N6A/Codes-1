import java.util.Scanner;

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    private static int ans = 0;
    private static int[] num = new int[1001];
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (k == n - 1 || k == 0) System.out.println("1");
            else if (n < 10) {
                for (int i = 0; i < n; ++i) num[i] = i;
                dfs(0, n, k);
                System.out.println(ans);
            }
        }
    }
    
    private static void dfs(int p, int n, int k) {
        if (p == n) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (num[i] < num[i + 1]) ++cnt;
            }
            if (cnt == k) ans = (ans + 1) % 2017;
            return;
        }
        for (int i = p; i < n; ++i) {
            int temp = num[p];
            num[p] = num[i];
            num[i] = temp;
            dfs(p + 1, n, k);
            temp = num[p];
            num[p] = num[i];
            num[i] = temp;
        }
    }
}