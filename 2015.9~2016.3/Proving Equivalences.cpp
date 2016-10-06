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
const int MAXN = 2e4 + 111;

vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN], indeg[MAXN], outdeg[MAXN];
bool in[MAXN];
int scnt, cnt, top;

void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    sta[top++] = u;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v; ++scnt;
        do{
            v = sta[--top];
            in[v] = 0;
            belong[v] = scnt;
        }while (u != v);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m, a, b; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) G[i].clear(), dfn[i] = low[i] = in[i] = 0;
        while (m --)
        {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
        }

        scnt = cnt = top = 0;
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) tarjan(i);

        for (int i = 1; i <= scnt; ++i) indeg[i] = outdeg[i] = 1;

        for (int u = 1; u <= n; ++u)
            for (int j = 0; j < G[u].size(); ++j)
            {
                int v = G[u][j];
                if (belong[u] != belong[v]) indeg[belong[v]] = outdeg[belong[u]] = 0;
            }

        int a = 0, b = 0;
        for (int i = 1; i <= scnt; ++i)
        {
            if (indeg[i]) ++a;
            if (outdeg[i]) ++b;
        }

        int ans = max(a, b);
        if (scnt == 1) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
