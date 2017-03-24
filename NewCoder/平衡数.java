import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {//注意while处理多个case
        	boolean ok = false;
            String s = in.next();
            int len = s.length();
            long[] suml = new long[len], sumr = new long[len];
            
            suml[0] = s.charAt(0) - '0';
            for (int i = 1; i < len; ++i) {
            	suml[i] = suml[i - 1] * (s.charAt(i) - '0');
            }
            
            sumr[len - 1] = s.charAt(len - 1) - '0';
            for (int i = len - 2; i >= 0; --i) {
            	sumr[i] = sumr[i + 1] * (s.charAt(i) - '0');
            }
            
            for (int i = 0; i < len - 1; ++i) {
            	if (suml[i] == sumr[i + 1]) {
            		ok = true;
            		break;
            	}
            }
            
            System.out.println(ok ? "YES" : "NO");
        }
        in.close();
    }
}