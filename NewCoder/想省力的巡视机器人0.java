import java.util.Scanner;

public class Main {
	
	private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    
    public static int dfs(int x, int y, int X, int Y, int[][] dp, int[][] mp) {
    	if (dp[x][y] != -1) return dp[x][y];
    	dp[x][y] = 1;
    	for (int i = 0; i < 4; ++i) {
    		int nx = x + dx[i], ny = y + dy[i];
    		if (0 <= nx && nx < X && 0 <= ny && ny < Y && mp[x][y] > mp[nx][ny]) {
    			dp[x][y] = Math.max(dp[x][y], 1 + dfs(nx, ny, X, Y, dp, mp));
    		}
    	}
    	return dp[x][y];
    }
	
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int x = in.nextInt(), y = in.nextInt();
            int[][] dp = new int[x][y];
            int[][] map = new int[x][y];
            for (int i = 0; i < x; ++i) {
            	for (int j = 0; j < y; ++j) {
            		map[i][j] = in.nextInt();
            		dp[i][j] = -1;
            	}
            }
            
            int ans = 0;
            for (int i = 0; i < x; ++i) {
            	for (int j = 0; j < y; ++j) {
            		if (dp[i][j] == -1) {
            			dfs(i, j, x, y, dp, map);
            		}
            		ans = Math.max(ans, dp[i][j]);
            	}
            }
            System.out.println(ans);
        }
        in.close();
    }
}