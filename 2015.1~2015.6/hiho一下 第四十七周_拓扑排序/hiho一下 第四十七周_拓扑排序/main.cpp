#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int MAXN = 1e5 + 111;

int deg[MAXN];
int head[MAXN];
int p[MAXN];
int nxt[MAXN];
int edgecnt;

void addedge(int u, int v)
{
    p[++edgecnt] = v;
    nxt[edgecnt] = head[u];
    head[u] = edgecnt;
}

int main()
{
    int t, n, m; scanf("%d", &t);
    while (t --)
    {
        edgecnt = 0;
        queue<int> q;
        memset(deg, 0, sizeof(deg));
        memset(head, 0, sizeof head);
        scanf("%d %d", &n, &m);
        int u, v;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &u, &v);
            addedge(u, v);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = head[i]; j; j = nxt[j])
            {
                int v = p[j];
                ++deg[v];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!deg[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (int i = head[v]; i; i = nxt[i])
            {
                int vv = p[i];
                if (deg[vv])
                {
                    --deg[vv];
                    if (!deg[vv])
                    {
                        q.push(vv);
                    }
                }
            }
        }
        bool flag = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (deg[i])
            {
                flag = 0;
                printf("Wrong\n");
                break;
            }
        }
        if (flag)
            printf("Correct\n");
    }
    return 0;
}