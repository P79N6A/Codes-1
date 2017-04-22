import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		int left = getLen(n), right = getLen(m);
		//System.out.println(left + " " + right);
		int ans = 0;
		if (left + right <= 7) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (ok(i, j, left, right)) {
						++ans;
					}
				}
			}
		}
		System.out.println(ans);
	}
	
	private static int getLen(int n) {
		int x = 7, ret = 1;
		while (true) {
			if (x >= n) return ret;
			++ret;
			x *= 7;
		}
	}
	
	private static boolean ok(int x, int y, int left, int right) {
		int[] cnt = new int[7];
		for (int i = 0; i < left; ++i) {
			if (++cnt[x % 7] > 1) return false;
			x /= 7;
		}
		for (int j = 0; j < right; ++j) {
			if (++cnt[y % 7] > 1) return false;
			y /= 7;
		}
		return true;
	}
}