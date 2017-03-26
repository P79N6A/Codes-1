import java.util.*;

public class Main {
	
	private static int h, i, o;
	
	private static boolean ok() {
		return h == 2 && i == 1 && o == 1;
	}
	
	private static void cal(char c, int add) {
		if (c == 'h') {
			h += add;
		}
		else if (c == 'i') {
			i += add;
		}
		else if (c == 'o') {
			o += add;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String s = in.next();
			int ans = 1000000, l = 0;
			h = 0;
			i = 0;
			o = 0;
			for (int r = 0; r < s.length(); ++r) {
				cal(s.charAt(r), 1);
				if (ok()) {
					//System.out.println(l + "  " + r);
					ans = Math.min(ans, r - l + 1);
				}
				while (l < r && (h > 2 || i > 1 || o > 1)) {
					cal(s.charAt(l), -1);
					++l;
				}
				while (l < r && s.charAt(l) != 'h' && s.charAt(l) != 'i' && s.charAt(l) != 'o') {
					++l;
				}
				if (ok()) {
					ans = Math.min(ans, r - l + 1);
				}
			}
			if (ans == 1000000) ans = -1;
			System.out.println(ans);
		}
		in.close();
	}
}