#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
double x[60], y[60];
int cnt, p[60], n;
bool vis[60];
struct Edge{
    int u, v;
    double dis;
    bool operator < (const Edge &t)const
    {
        return dis < t.dis;
    }
}e[4000];

void add_edge(int u, int v, double dis)
{
    e[cnt].u = u; e[cnt].v = v; e[cnt].dis = dis;
    ++cnt;
}

double getdis(int a, int b)
{
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx*dx + dy*dy);
}

void init()
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = i;
    }
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

double kruskal()
{
    double ret = 0;
    for (int i = 0; i < cnt; ++i)
    {
        Edge &temp = e[i];
        if (vis[e[i].u] || vis[e[i].v]) continue;
        int px = find(e[i].u), py = find(e[i].v);
        if (px != py)
        {
            p[px] = py;
            ret += e[i].dis;
        }
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &x[i], &y[i]);
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                double d = getdis(i, j);
                add_edge(i, j, d);
                add_edge(j, i, d);
            }
        memset(vis, 0, sizeof vis);
        sort(e, e + cnt);
        double ans = INF;
        for (int i = 0; i < n; ++i)
        {
            vis[i] = 1;
            init();
            ans = min(ans, kruskal());
            vis[i] = 0;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

