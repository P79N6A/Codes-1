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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

struct P {
    int u, v, w;
}ans[MAXN];
int cnt = 0;
vector<pii> G[MAXN];
int mi[MAXN];
int vis[MAXN];
int to[MAXN];
bool in[MAXN];

bool dfs(int u, int org) {
    vis[u] = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i].first, d = G[u][i].second;
        if (vis[v] == -1) return 0;
        if (vis[v] == 1) continue;
        to[org] = v;
        mi[v] = min(mi[u], d);
        if (!dfs(v, org))
            return 0;
    }
    vis[u] = 1;
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        in[v] = 1;
        G[u].push_back(make_pair(v, w));
    }
    memset(mi, 0x3f, sizeof mi);
    for (int i = 1; i <= n; ++i) {
        if (!in[i] && !vis[i] && G[i].size() && dfs(i, i)) {
            ans[cnt].u = i;
            ans[cnt].v = to[i];
            ans[cnt].w = mi[to[i]];
            ++cnt;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        cout << ans[i].u << ' ' << ans[i].v << ' ' << ans[i].w << '\n';
    }
    return 0;
}
