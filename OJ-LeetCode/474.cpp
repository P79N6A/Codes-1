class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        int zero[606], one[606];
        memset(zero, 0, sizeof zero);
        memset(one, 0, sizeof one);
        for (int i = 0; i < str.size(); ++i) {
            for (int j = 0; j < str[i].length(); ++j) {
                if (str[i][j] == '1') ++one[i];
                else ++zero[i];
            }
        }
        
        int dp[2][101][101];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < str.size(); ++i) {
            int cur = i % 2;
            int last = 1 - cur;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[cur][j][k] = dp[last][j][k];
                    if (j >= zero[i] && k >= one[i]) {
                        dp[cur][j][k] = max(dp[cur][j][k], dp[last][j - zero[i]][k - one[i]] + 1);
                    }
                }
            }
        }
        int cur = (str.size() - 1) % 2;
        int ans = 0;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                ans = max(ans , dp[cur][j][k]);
            }
        }
        return ans;
    }
};