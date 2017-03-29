import java.util.*;

public class Main {
    
    private static double[] num = new double[4];
    private static double eps = 1e-10;
    
    private static boolean dfs(int n) {
        if (n == 1) {
            if (Math.abs(num[0] - 24.0) < eps) return true;
            else return false;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    double x = num[i], y = num[j];
                    num[j] = num[n - 1];
                    
                    num[i] = x + y;
                    if (dfs(n - 1)) return true;
                    
                    num[i] = x - y;
                    if (dfs(n - 1)) return true;
                    
                    num[i] = x * y;
                    if (dfs(n - 1)) return true;
                    
                    num[i] = x / y;
                    if (dfs(n - 1)) return true;
                    
                    num[i] = x;
                    num[j] = y;
                }
            }
        }
        return false;
    }
    
    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 4; ++i) {
            num[i] = in.nextDouble();
        }
        if (dfs(4)) System.out.println("yes");
        else System.out.println("no");
        in.close();
    }
}
