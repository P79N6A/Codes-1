import java.io.*;
/**
 * 考虑4 * 25 = 100
 * 那么就能肯定如果十位和个位构成
 * 的数能够被4整除,那么高位不论是
 * 多少,都能被整除。接着再单独考虑
 * 个位的情况即可。
 * @author GooZy
 */

public class Main {
    
    public static void main(String[] args) throws IOException {
        PrintWriter pr;
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            String s = in.readLine();
            long ans = 0;
            for (int i = 0; i < s.length() - 1; ++i) {
                int val = Integer.parseInt(s.substring(i, i + 2));
                if (val % 4 == 0) {
                    ans += i + 1;
                }
            }
            for (int i = 0; i < s.length(); ++i) {
                if (Integer.parseInt(s.substring(i, i + 1)) % 4 == 0) ++ans;
            }
            pr = new PrintWriter(new OutputStreamWriter(System.out));
            pr.println(ans);
        }
        pr.close();
    }
}