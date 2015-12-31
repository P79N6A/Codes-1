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
const int MAXN = 5e4 + 111;

struct Edge{
    int u, v, next;
    ll w;
}edge[MAXN * 2];

int vis[MAXN], newid[MAXN], pre[MAXN], in[MAXN], head[MAXN], vvis[MAXN];

ll zhuLiu(int rt, int n, int m)
{
    ll ret = 0;
    while (1)
    {
        for (int i = 0; i < n; ++i) in[i] = INF;
        for (int i = 0; i < m; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            if (u != v && in[v] > edge[i].w)
            {
                pre[v] = u;
                in[v] = edge[i].w;
            }
        }

        if (in[rt] < INF) break;

        int cnt = 0;
        memset(newid, -1, sizeof newid);
        memset(vis, -1, sizeof vis);
        in[rt] = 0;
        for (int i = 0; i < n; ++i)
        {
            ret += in[i];
            int v = i;
            while (vis[v] != i && newid[v] == -1 && v != rt)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (newid[v] == -1 && v != rt)
            {
                for (int u = pre[v]; u != v; u = pre[u])
                {
                    newid[u] = cnt;
                }
                newid[v] = cnt++;
            }
        }

        if (cnt == 0) break;
        for (int i = 0; i < n; ++i) if (newid[i] == -1) newid[i] = cnt++;
        for (int i = 0; i < m; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            edge[i].u = newid[u];
            edge[i].v = newid[v];
        }
        n = cnt;
        rt = newid[rt];
    }
    return ret;
}

bool dfs(int s, int x, int flag)
{
    vvis[s] = flag;
    for (int i = head[s]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == x)
        {
            edge[i].w = 0;
            return 1;
        }
        else if (vvis[v] != flag && dfs(v, x, flag))
        {
            edge[i].w = 0;
            return 1;
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int flag = 0;
        memset(head, -1, sizeof head);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%lld", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].next = head[edge[i].u];
            head[edge[i].u] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(i, i, flag++);
        }
        printf("%lld\n", zhuLiu(0, n, m));
    }
    return 0;
}
