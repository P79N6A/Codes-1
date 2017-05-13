import java.util.*;
/**
 * dp[i]:到i为止的最大值
 * 注意初始化
 * @author GooZy
 */

public class Main {
	
	public static void main(String[] args) {
		int n, w, h;
		Scanner in = new Scanner(System.in);
		n = in.nextInt() + 1;
		w = in.nextInt();
		h = in.nextInt();
		Envelope[] en = new Envelope[n];
		en[0] = new Envelope(w, h, 0);
		for (int i = 1; i < n; ++i) {
			en[i] = new Envelope(in.nextInt(), in.nextInt(), i);
		}
		Arrays.sort(en, 1, n);
		int[] pre = new int[n];
		int[] dp = new int[n];
		Arrays.fill(dp, -100000);
		dp[0] = 0;
		int mx = 0, ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (en[i].greater(en[j]) && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
			if (dp[i] > mx) {
				mx = dp[i];
				ans = i;
			}
		}
		System.out.println(dp[ans]);
		ArrayList<Integer> al = new ArrayList<>();
		while (ans != 0) {
			al.add(en[ans].id);
			ans = pre[ans];
		}
		for (int i = al.size() - 1; i >= 0; --i) {
			System.out.print(String.valueOf(al.get(i)) + (i == 0 ? '\n' : ' '));
		}
	}
}

class Envelope implements Comparable<Envelope> {
	int w, h, id;
	public Envelope(int w, int h, int id) {
		this.w = w;
		this.h = h;
		this.id = id;
	}
	
	@Override
	public int compareTo(Envelope o) {
		if (w == o.w) return h - o.h;
		return w - o.w;
	}
	
	public boolean greater(Envelope o) {
		return w > o.w && h > o.h;
	}
}