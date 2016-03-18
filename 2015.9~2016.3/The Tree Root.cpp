#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int dis[MAXN], mxdep, ed;
vector<vector<int> > G;

void dfs(int u, int fa, int dep)
{
    if (dep > mxdep) mxdep = dep, ed = u;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (v == fa) continue;
        dfs(v, u, dep + 1);
        dis[v] = max(dis[v], dep + 1);
    }
}

int main()
{
    int n, cnt, x;
    while (~scanf("%d", &n))
    {
        G.clear();
        G.resize(n + 2);
        memset(dis, 0, sizeof(int) * (n + 2));

        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &cnt);
            for (int j = 0; j < cnt; ++j)
            {
                scanf("%d", &x);
                G[i].push_back(x);
            }
        }

        mxdep = 0;
        dfs(1, -1, 0);      // �ҵ���Զ�˵�
        dfs(ed, -1, 0);     // �������е㵽�ö˵���룬��������һ���˵�
        dfs(ed, -1, 0);     // ���е㵽�ö˵�ľ���

        int mi = INF;
        for (int i = 1; i <= n; ++i) mi = min(mi, dis[i]);

        printf("Best Roots  :");
        for (int i = 1; i <= n; ++i) if (dis[i] == mi) printf(" %d", i);
        puts("");

        printf("Worst Roots :");
        for (int i = 1; i <= n; ++i) if (dis[i] == mxdep) printf(" %d", i);
        puts("");
    }
    return 0;
}
