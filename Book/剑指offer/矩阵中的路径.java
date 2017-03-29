public class Solution {
    
    int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    boolean[][] vis;
    int row, col;
    
    boolean ok(int nx, int ny) {
        return 0 <= nx && nx < row && 0 <= ny && ny < col && !vis[nx][ny];
    }
    
    boolean dfs(char[] matrix, int x, int y, char[] str, int pos) {
        if (pos == str.length) return true;
        //System.out.println(x + " " + y + ":" + pos);
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && matrix[nx * col + ny] == str[pos] && dfs(matrix, nx, ny, str, pos + 1)) {
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str) {
        if (matrix == null || str == null) return false;
        vis = new boolean[rows][cols];
        row = rows;
        col = cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i * cols + j] == str[0] && dfs(matrix, i, j, str, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
}