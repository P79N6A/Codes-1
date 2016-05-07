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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

vector<int> G[MAXN];
vector<int> rG[MAXN], vs;
bool vis[MAXN];
int indx[MAXN], n;

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!vis[v]) dfs(v);
    }
    vs.push_back(u);
}

void rdfs(int u, int dx) {
    indx[u] = dx;
    vis[u] = 1;
    for (int i = 0; i < rG[u].size(); ++i) {
        int v = rG[u][i];
        if (!vis[v])
            rdfs(v, dx);
    }
}

int scc() {
    memset(vis, 0, sizeof vis);
    vs.clear();
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    for (int i = vs.size() - 1; i >= 0; --i) {
        if (!vis[vs[i]]) rdfs(vs[i], ++cnt);
    }
    return cnt;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, u, v;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) G[i].clear(), rG[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            rG[v].push_back(u);
        }

        int V = scc();

        int st, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (indx[i] == V) {
               st = i;
               ++ans;
            }
        }
        memset(vis, 0, sizeof vis);
        rdfs(st, 0);
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans = 0;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
