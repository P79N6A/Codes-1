import java.util.Scanner;

public class Main {
	
	static int limit, n, ans;
	static int[][] mp;
	static int[] par;
	
	public static void dfs(int x, int len) {
		ans = Math.max(ans, len);
		for (int i = 0; i < n; ++i) {
			if (mp[x][i] != 0 && len + mp[x][i] <= limit) {
				dfs(i, len + mp[x][i]);
			}
		}
	}
	
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
        	limit = in.nextInt();
        	n = in.nextInt();
        	par = new int[n];
        	mp = new int[n][n];
        	for (int i = 0; i < n; ++i) par[i] = -1;
        	for (int i = 1; i < n; ++i) {
        		int u = in.nextInt();
        		int v = in.nextInt();
        		int w = in.nextInt();
        		mp[u][v] = mp[v][u] = w;
        		par[v] = u;
        	}
        	ans = 0;
        	for (int i = 0; i < n; ++i) {
        		if (par[i] == -1) {
        			dfs(i, 0);
        			break;
        		}
        	}
        	System.out.println(ans);
        }
        in.close();
    }
}