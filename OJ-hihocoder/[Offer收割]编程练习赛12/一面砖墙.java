import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static final int MAXN = 1000;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            int sum = 0;
            for (int j = 0; j < x; ++j) {
                sum += in.nextInt();
                if (j == x - 1) continue;
                if (mp.containsKey(sum)) {
                    mp.put(sum, mp.get(sum) + 1);
                }
                else mp.put(sum, 1);
            }
        }
        int ans = 0;
        for (int x : mp.values()) {
            ans = Math.max(ans, x);
        }
        System.out.println(n - ans);
        in.close();
    }
}