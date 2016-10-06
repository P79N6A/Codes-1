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

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

int t, a, b, m, l, k, u, v, w, n;
int dis[MAXN][MAXN];
int pass[MAXN][MAXN];
int dp[MAXN][20];

void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                if (i <= a) {
                    pass[j][k] = min(pass[j][k], pass[j][i] + pass[i][k]);
                }
            }
        }
    }
    //printf("dis1n = %d\n", dis[1][n]);
}

void solve() {
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dis[n][i];
    }
    for (int i = 1; i <= k; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (pass[v][u] <= l) {
                    //printf("%d -> %d\n", v, u);
                    dp[u][i] = min(dp[u][i], dp[v][i - 1]);
                }
            }
        }
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (dp[u][i] > dp[v][i] + dis[v][u]) {
                    dp[u][i] = dp[v][i] + dis[v][u];
                }
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> a >> b >> m >> l >> k;
        n = a + b;
        memset(dis, 0x3f, sizeof dis);
        memset(pass, 0x3f, sizeof pass);
        while (m --) {
            cin >> u >> v >> w;
            dis[u][v] = dis[v][u] = min(dis[u][v], w);
            pass[u][v] = pass[v][u] = dis[u][v];
        }
        init();
        solve();
        printf("%d\n", dp[1][k]);
    }
    return 0;
}
