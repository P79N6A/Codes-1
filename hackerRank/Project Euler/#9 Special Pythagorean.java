
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            long ans = -1;
            int up = n / 3;
            for (int a = 1; a <= up; ++a) {
                if (n * (n - 2 * a) % (2 * n - 2 * a) == 0) {
                    int b = n * (n - 2 * a) / (2 * n - 2 * a);
                    int c = n - a - b;
                    if ((a < b && b < c) && (a * a + b * b == c * c)) {
                        ans = (long)a * b * c;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
