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
int dfn[MAXN], low[MAXN], sta[MAXN];
int top, scnt, cnt;
bool in[MAXN];

void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    sta[top++] = u; in[u] = 1;
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
        }while (u != v);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, a, b;
    while (~scanf("%d%d", &n, &m) && (n | m))
    {
        for (int i = 1; i <= n; ++i) G[i].clear(), dfn[i] = low[i] = in[i] = 0;
        while (m --)
        {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
        }

        scnt = top = cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) tarjan(i);

        if (scnt == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
