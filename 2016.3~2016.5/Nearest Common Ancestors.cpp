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
int par[MAXN], dep[MAXN];

void dfs(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase, n; scanf("%d", &kase);
    while (kase --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) G[i].clear(), par[i] = i;
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            par[v] = u;
            G[u].push_back(v);
        }
        scanf("%d%d", &u, &v);

        int rt = 0;
        for (int i = 1; i <= n; ++i) {
            if (par[i] == i) {
                rt = i;
                break;
            }
        }
        dep[rt] = 0;
        dfs(rt);

        while (dep[u] < dep[v]) v = par[v];
        while (dep[v] < dep[u]) u = par[u];
        while (u != v) {
            u = par[u];
            v = par[v];
        }
        printf("%d\n", u);
    }
    return 0;
}
