import java.util.Scanner;

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    private static final double eps = 1e-7;
    
    static class Triangel {
        int color;
        double x, y, z;
        public Triangel(String c, double x, double y, double z) {
            color = c.charAt(0);
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            Triangel[] tr = new Triangel[n];
            for (int i = 0; i < n; ++i) {
                tr[i] = new Triangel(in.next(), in.nextDouble(), 
                        in.nextDouble(), in.nextDouble());
            }
            double ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        double temp = cal(tr[i], tr[j], tr[k]);
                        if (temp - ans > eps) ans = temp;
                    }
                }
            }
            System.out.printf("%.5f", ans);
        }
    }
    
    private static double cal(Triangel a, Triangel b, Triangel c) {
        if (a.color == b.color && b.color == c.color ||
                (a.color != b.color && b.color != c.color && c.color != a.color)) {
            double la = getDis(a, b);
            double lb = getDis(a, c);
            double lc = getDis(b, c);
            double p = (la + lb + lc) / 2;
            return Math.sqrt(p * (p - la) * (p - lb) * (p - lc));
        }
        return 0;
    }

    
    private static double getDis(Triangel a, Triangel b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        double dz = a.z - b.z;
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }
}