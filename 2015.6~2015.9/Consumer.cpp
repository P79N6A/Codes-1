#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e5 + 111;
ll dp[52][MAXN];
int p[60], m[60], c[60][20], v[60][20];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, w;
    while (~scanf("%d%d", &n, &w))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &p[i], &m[i]);
            for (int j = 0; j < m[i]; ++j)
            {
                scanf("%d%d", &c[i][j], &v[i][j]);
            }
        }
        memset(dp, -0x7f, sizeof dp);
        for (int i = 0; i <= w; ++i) dp[0][i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = p[i]; j <= w; ++j)
                dp[i][j] = dp[i - 1][j - p[i]];
            for (int j = 0; j < m[i]; ++j)
                for (int k = w; k >= c[i][j]; --k)
                {
                    dp[i][k] = max(dp[i][k], dp[i][k - c[i][j]] + v[i][j]);
                }
            for (int j = 0; j <= w; ++j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        printf("%lld\n", dp[n][w]);
    }
    return 0;
}
