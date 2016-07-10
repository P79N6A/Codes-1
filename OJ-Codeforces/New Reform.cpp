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
const int MAXN = 1e5 + 111;

int low[MAXN], dfn[MAXN], in[MAXN], indx;
vector<int> G[MAXN];

bool tarjan(int u, int f) {
    bool ret = 0;
    low[u] = dfn[u] = ++indx;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f) continue;
        if (!dfn[v]) {
            ret |= tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] <= dfn[u]) {
                ret = 1;
            }
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    in[u] = 0;
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    while (m --) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i] && !tarjan(i, i)) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
