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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 111;

bool ok[MAXN], in[MAXN];
int who[MAXN], head[MAXN], to[MAXN * 2], nxt[MAXN * 2], val[MAXN * 2];
int cnt, enter[MAXN], dis[MAXN], n, m;

void add_edge(int u, int v, int w)
{
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

bool spfa(int s)
{
    queue<int> q;
    q.push(s);
    in[s] = 1;
    dis[s] = 0;
    ++enter[s];
    while (q.size())
    {
        int cur = q.front(); q.pop();
        who[cur] = s;
        in[cur] = 0;
        for (int i = head[cur]; ~i; i = nxt[i])
        {
            int v = to[i];
            if (dis[v] > dis[cur] + val[i])
            {
                dis[v] = dis[cur] + val[i];
                if (!in[v])
                {
                    in[v] = 1;
                    who[v] = s;
                    ++enter[v];
                    q.push(v);
                    if (enter[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, u, v, w;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        int cnt = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            head[i] = -1, ok[i] = 0, who[i] = -1;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }

        bool possible = 0;
        for (int i = 0; i < n; ++i)
            if (who[i] == -1)
            {
                memset(in, 0, sizeof(bool)*(n + 2));
                memset(enter, 0, sizeof(int)*(n + 2));
                memset(dis, 0x3f, sizeof(int)*(n + 2));
                if (spfa(i)) ok[i] = 1, possible = 1;
            }

        printf("Case %d:", kase);
        if (possible)
        {
            for (int i = 0; i < n; ++i)
            {
                if (ok[who[i]]) printf(" %d", i);
            }
            puts("");
        }
        else printf(" impossible\n");
    }
    return 0;
}
