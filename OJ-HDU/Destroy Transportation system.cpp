#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 205;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

struct Pt {
    int v, d, b;
};
vector<Pt> G[maxn];
bool vis[maxn];
int dp[maxn], bak[maxn];

bool dfs(int u) {
    if (dp[u] < 0) return 0;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        Pt &temp = G[u][i];
        int v = temp.v, d = temp.d, b = temp.b;
        if (vis[v]) continue;
        int nxt = dp[u] + dp[v] - b;
        for (int j = 0; j < G[v].size(); ++j) {
            Pt &tt = G[v][j];
            int v = tt.v, d = tt.d, b = tt.b;
            if (vis[v]) {
                nxt -= b;
            }
        }
        if (nxt <= dp[u]) {
            dp[u] = nxt;
            if (!dfs(v)) return 0;
        }
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v, d, b, n, m;
    for (int t, kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) G[i].clear(), dp[i] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &u, &v, &d, &b);
            G[u].push_back(Pt{v, d, b});
            dp[u] -= d;
            dp[v] += d + b;
        }
        bool flag = 1;
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            memcpy(bak, dp, sizeof(dp[0]) * (n + 1));
            if (!dfs(i)) {
                flag = 0;
                break;
            }
            memcpy(dp, bak, sizeof(bak[0]) * (n + 1));
        }
        printf("Case #%d: ", kase);
        if (flag) puts("happy");
        else puts("unhappy");
    }
    return 0;
}
