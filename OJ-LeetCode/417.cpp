int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

class Solution {
public:
    
    bool ok(int x, int y) {
        return (0 <= x && x < n && 0 <= y && y < m);
    }
    
    void dfs(vector<vector<bool>> &vis, int x, int y, vector<vector<int>>& matrix) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (ok(nx, ny) && !vis[nx][ny] && matrix[x][y] <= matrix[nx][ny]) {
                dfs(vis, nx, ny, matrix);
            }
        }
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if (matrix.size() == 0) return ans;
        
        n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m));
        vector<vector<bool>> vis2(n, vector<bool>(m));
        
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
                    ans.push_back(make_pair(i, j));
                }
            }
        }
        return ans;
    }
    
private:
    int n, m;
};