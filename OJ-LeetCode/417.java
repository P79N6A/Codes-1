public class Solution {
    static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    public boolean ok(int x, int y) {
        return (0 <= x && x < n && 0 <= y && y < m);
    }
    
    public void dfs(boolean[][] vis, int x, int y, int[][] matrix) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (ok(nx, ny) && !vis[nx][ny] && matrix[x][y] <= matrix[nx][ny]) {
                dfs(vis, nx, ny, matrix);
            }
        }
    }
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        n = matrix.length;
        if (n == 0) return res;
        m = matrix[0].length;
        
        boolean[][] vis1 = new boolean[n][m];
        boolean[][] vis2 = new boolean[n][m];
        
        for (int i = 0; i < m; ++i) {
            if (!vis1[0][i]) {
                dfs(vis1, 0, i, matrix);
            }
            if (!vis2[n - 1][i]) {
                dfs(vis2, n - 1, i, matrix);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (!vis1[i][0]) {
                dfs(vis1, i, 0, matrix);
            }
            if (!vis2[i][m - 1]) {
                dfs(vis2, i, m - 1, matrix);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis1[i][j] && vis2[i][j]) {
                    res.add(new int[]{i, j});
                }
            }
        }
        return res;
    }
    
    private int n, m;
}