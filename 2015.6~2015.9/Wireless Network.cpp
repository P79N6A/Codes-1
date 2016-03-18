#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int p[MAXN];
bool repair[MAXN];
double x[MAXN], y[MAXN];
vector<int> G[MAXN]; //记录可达点

double getDis(int a, int b)
{
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx*dx + dy*dy);
}

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}

void unite(int a, int b)
{
    a = find(a), b = find(b);
    p[a] = b;
}

int main()
{
    int n, a, b;
    double d;
    scanf("%d%lf", &n, &d);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        scanf("%lf%lf", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (getDis(i, j) <= d)
            {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    char op[2];
    while (~scanf("%s", op))
    {
        if (op[0] == 'O')
        {
            scanf("%d", &a);
            repair[a] = 1;
            for (int i = 0; i < G[a].size(); ++i) //合并更新点周围被更新的点
            {
                int v = G[a][i];
                if (repair[v]) unite(a, v);
            }
        }
        else
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
