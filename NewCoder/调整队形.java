import java.util.Scanner;


public class Main {
	
	private static String s;
	
	private static int getAns(char w) {
		int ans1 = 0, base = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == w) {
				ans1 +=  i - base;
				++base;
			}
		}
		int ans2 = 0;
		base = s.length() - 1;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s.charAt(i) == w) {
				ans2 += base - i;
				--base;
			}
		}
		return Math.min(ans1, ans2);
	}
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        int cntg = 0, cntb = 0;
        for (int i = 0; i < s.length(); ++i) {
        	if (s.charAt(i) == 'B') ++cntb;
        	else ++cntg;
        }
        int ans = 0;
        if (cntb != 0 && cntg != 0) {
        	ans = Math.min(getAns('B'), getAns('G'));
        }
        System.out.println(ans);
        sc.close();
	}
}