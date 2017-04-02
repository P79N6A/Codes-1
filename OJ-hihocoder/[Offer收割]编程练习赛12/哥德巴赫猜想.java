import java.util.*;

public class Main {
    
    private static final int INF = 100000000;
    private static final int MAXN = 1000;
    
    static boolean ok(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 2; i < n - 1; ++i) {
            int x = i, y = n - i;
            if (ok(x) && ok(y)) {
                System.out.println(x + " " + y);
                break;
            }
        }
        in.close();
    }
}