import java.util.*;

public class Main {
    
    private static final int MOD = (int)1e9 + 7;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] s = in.next().toCharArray();
        int ans = 0;
        int cnt = 0;
        int tol = 0;
        long sum = 1;
        for (int i = 0; i < s.length; ++i) {
            if (s[i] == '(') ++cnt;
            else {
                --cnt;
                ++tol;
            }
            if (cnt == -1) {
                ++ans;
                ++cnt;
                sum = (sum * tol) % MOD;
            }
        }
        if (ans == 0) System.out.println("0 0");
        else System.out.println(ans + " " + sum);
        in.close();
    }
}