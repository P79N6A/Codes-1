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
const int MAXN = 1e3 + 111;

struct Edge{
    int u, v, w;
}edge[20100];

int pre[MAXN], newid[MAXN], in[MAXN], vis[MAXN], ecnt, minV;

void add_edge(int u, int v, int w)
{
    edge[ecnt].u = u;
    edge[ecnt].v = v;
    edge[ecnt++].w = w;
}

int zhuLiu(int rt, int V)
{
    int ret = 0;
    while (1)
    {
        for (int i = 0; i <= V; ++i) in[i] = INF;
        for (int i = 0; i < ecnt; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            if (u != v && in[v] > edge[i].w)
            {
                in[v] = edge[i].w;
                pre[v] = u;
                if (u == rt) minV = i;
            }
        }

        int cnt = 0;
        memset(vis, -1, sizeof vis);
        memset(newid, -1, sizeof newid);
        in[rt] = 0;

        for (int i = 0; i <= V; ++i)
        {
            ret += in[i];
            int v = i;
            while (vis[v] != i && newid[v] == -1 && v != rt)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (v != rt && newid[v] == -1)
            {
                for (int u = pre[v]; u != v; u = pre[u])
                    newid[u] = cnt;
                newid[v] = cnt++;
            }
        }

        if (cnt == 0) break;
        for (int i = 0; i <= V; ++i)
            if (newid[i] == -1) newid[i] = cnt++;
        for (int i = 0; i < ecnt; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            edge[i].u = newid[u];
            edge[i].v = newid[v];
            if (newid[u] != newid[v]) edge[i].w -= in[v];
        }
        V = cnt - 1;
        rt = newid[rt];
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v, w;
    while (~scanf("%d%d", &n, &m))
    {
        int mxVal = 0;
        ecnt = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            mxVal += w;
        }
        ++mxVal;
        for (int i = 0; i < n; ++i)
        {
            add_edge(n, i, mxVal);
        }
        int ans = zhuLiu(n, n);
        if (ans >= 2 * mxVal) printf("impossible\n\n");
        else
        {
            printf("%d %d\n\n", ans - mxVal, minV - m);
        }
    }
    return 0;
}
