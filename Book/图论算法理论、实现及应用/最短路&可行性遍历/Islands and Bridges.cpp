/* 题意：
 * 找出图中的哈密顿回路值和个数
 */
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1 << 14;

ll dp[MAXN][15][15]; // dp[x][u][v]: 已经访问了x，前两个点为u, v的最大值
ll way[MAXN][15][15];
ll val[15];
bool mp[15][15];
vector<int> G[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &val[i]);
            G[i].clear();
        }
        int u, v;
        memset(dp, -1, sizeof dp);
        memset(way, 0, sizeof way);
        memset(mp, 0, sizeof mp);
        while (m --) {
            scanf("%d%d", &u, &v);
            --u, --v;
            int x = (1 << u) | (1 << v);
            dp[x][u][v] = dp[x][v][u] = val[u] * val[v] + val[u] + val[v];
            way[x][u][v] = way[x][v][u] = 1;
            G[u].push_back(v);
            G[v].push_back(u);
            mp[u][v] = mp[v][u] = 1;
        }

        int up = (1 << n);
        for (int i = 0; i < up; ++i) {
            if (__builtin_popcount(i) < 2) continue;
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j))) continue;
                for (int k = 0; k < n; ++k) {
                    if (!(i & (1 << k)) || dp[i][j][k] == -1) continue;
                    for (int l = 0; l < G[j].size(); ++l) {
                        int v = G[j][l];
                        if (i & (1 << v)) continue;
                        int nx = i | (1 << v);
                        ll tol = dp[i][j][k] + val[v] + val[v] * val[j];
                        if (mp[k][v]) tol += val[j] * val[k] * val[v];
                        if (dp[nx][v][j] < tol) {
                            dp[nx][v][j] = tol;
                            way[nx][v][j] = way[i][j][k];
                        }
                        else if (dp[nx][v][j] == tol) {
                            way[nx][v][j] += way[i][j][k];
                        }
                    }
                }
            }
        }

        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || !mp[i][j]) continue;
                if (dp[up - 1][i][j] > ans1) {
                    ans1 = dp[up - 1][i][j];
                    ans2 = way[up - 1][i][j];
                }
                else if (dp[up - 1][i][j] == ans1) {
                    ans2 += way[up - 1][i][j];
                }
            }
        }
        if (n == 1) ans1 = val[0], ans2 = 2;
        printf("%lld %lld\n", ans1, ans2 / 2);
    }
    return 0;
}
