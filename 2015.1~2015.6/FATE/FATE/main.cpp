#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 111;
typedef long long ll;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k, s;
    while(cin >> n >> m >> k >> s)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < k; ++i)
            cin >> a[i] >> b[i];
        for (int i = 0; i < k; ++i)
        {
            for (int j = b[i]; j <= m; ++j)
                for (int k = 1; k <= s; ++k)
                    dp[j][k] = max(dp[j][k], dp[j - b[i]][k - 1] + a[i]);
        }
        if (dp[m][s] < n)
            cout << -1 << '\n';
        else {
            for (int i = 0; i <= m; ++i)
                if (dp[i][s] >= n)
                {
                    cout << m - i << '\n';
                    break;
                }
        }
    }
    return 0;
}
