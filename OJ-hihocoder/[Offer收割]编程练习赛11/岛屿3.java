import java.util.*;

public class Main {
	
	private final static int MX = 1000100;
	private static int[] dx = {0, 0, 1, -1}, dy = {-1, 1, 0, 0};
	private static int[] par = new int[MX];
	private static int num = 0, cir = 0;
	
	private static int find(int x) {
		return x == par[x] ? x : (par[x] = find(par[x]));
	}
	
	private static void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		par[x] = par[y];
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		boolean[] vis = new boolean[MX];
		for (int i = 0; i < MX; ++i) {
			par[i] = i;
			vis[i] = false;
		}
		
		for (int i = 0; i < n; ++i) {
			int x = in.nextInt(), y = in.nextInt();
			int cur = x * 1000 + y;
			if (!vis[cur]) {
				vis[cur] = true;
				int cnt = 0;
				HashSet<Integer> hs = new HashSet<>();
				ArrayList<Integer> al = new ArrayList<>();
				for (int j = 0; j < 4; ++j) {
					int nx = x + dx[j], ny = y + dy[j];
					int nxt = nx * 1000 + ny;
					if (nx < 0 || nx >= 1000 || ny < 0 || ny >= 1000) continue;
					if (vis[nxt]) {
						++cnt;
						hs.add(find(nxt));
						al.add(nxt);
					}
				}
				if (cnt == 0) {
					++num;
				}
				else {
					num -= hs.size() - 1;
					for (int j : al) {
						unite(j, cur);
					}
				}
				//System.out.println(cnt);
				cir += 4 - 2 * cnt;
			}
			System.out.println(num + " " + (i + 1) + " " + cir);
		}
		
		in.close();
	}
}