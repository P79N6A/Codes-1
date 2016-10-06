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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 21;

int ans = INF, n;
bool vis[MAXN][1500];
int dp[MAXN][1500];

struct P {
    int to, w, c, p;
    P(int _to, int _w, int _c, int _p):to(_to),w(_w),c(_c),p(_p){};
};
vector<P> G[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, a, b, c, p, r;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d%d", &a, &b, &c, &p, &r);
        G[a].push_back(P(b, r, c, p));
    }

    memset(dp, 0x3f, sizeof dp);
    memset(vis, 0, sizeof vis);
    dp[1][1] = 0;
    vis[1][1] = 1;
    queue<pii> q;
    q.push(pii(1, 1));
    while (q.size()) {
        pii cur = q.front(); q.pop();
        int u = cur.first, sta = cur.second;
        vis[u][sta] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].to;
            int nxs = sta | (1 << (v - 1));
            if ((sta & (1 << (G[u][i].c - 1))) && dp[v][nxs] > dp[u][sta] + G[u][i].p) {
                dp[v][nxs] = dp[u][sta] + G[u][i].p;
                if (!vis[v][nxs]) {
                    q.push(pii(v, nxs));
                    vis[v][nxs] = 1;
                }
            }
            if (dp[v][nxs] > dp[u][sta] + G[u][i].w) {
                dp[v][nxs] = dp[u][sta] + G[u][i].w;
                if (!vis[v][nxs]) {
                    q.push(pii(v, nxs));
                    vis[v][nxs] = 1;
                }
            }
        }
    }

    for (int i = 1; i < (1 << n); ++i) ans = min(ans, dp[n][i]);
    if (ans == INF) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}
