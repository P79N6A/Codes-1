import java.util.Scanner;

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            int[] appear = new int[1001];
            for (int i = 0; i < n; ++i) {
                ++appear[in.nextInt()];
            }
            int cnt = 0, ans = -1;
            for (int i = 1; i <= 1000; ++i) {
                if (appear[i] != 0 && ++cnt == 3) {
                    ans = i;
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}