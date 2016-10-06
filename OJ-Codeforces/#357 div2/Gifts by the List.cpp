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

vector<int> G[MAXN];
vector<int> V[MAXN];
int par[MAXN], give[MAXN];
bool in[MAXN];
int ans[MAXN], cnt = 0;

void dfs(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        dfs(v);
    }
    if (u == give[u]) ans[cnt++] = u;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    while (m --) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        par[v] = u;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &give[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (give[i] != i && give[i] != give[par[i]]) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (par[i] == i) {
            dfs(i);
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) printf("%d\n", ans[i]);
    return 0;
}
