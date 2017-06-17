import java.io.*;

public class Main {
    
    private static final int MAXN = (int)(1e5 + 10);
    
    public static void main(String[] args) throws IOException {
        PrintWriter pr;
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {    
            pr = new PrintWriter(new OutputStreamWriter(System.out));
            int n = Integer.parseInt(in.readLine());
            int big = 0, small = 0, org = 0;
            String[] num = in.readLine().split(" ");
            org = Integer.parseInt(num[0]);
            for (int i = 1; i < n; ++i) {
                int x = Integer.parseInt(num[i]);
                if (x > org) ++big;
                else ++small;
            }
            int ans = 0;
            while (small != 0) {
                if (big % 2 != 0) {
                    small = (small - 1) / 2;
                    big = big / 2 + 1;
                }
                else {
                    big /= 2;
                    small /= 2;
                }
                ++ans;
            }
            pr.println(ans);
        }
        pr.close();
    }
}