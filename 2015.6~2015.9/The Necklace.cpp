#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 111;
int c[MAXN], g[MAXN], vis[MAXN][MAXN];
vector<int> v[MAXN];

void euler(int u)
{
    for (int i = 0; i < v[u].size(); ++i)
    {
        int cur = v[u][i];
        if (vis[u][cur])
        {
            --vis[u][cur]; --vis[cur][u];
            euler(cur);
            printf("%d %d\n", cur, u);
        }
    }
}

int main()
{
    int t, n, a, b;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < MAXN; ++i) v[i].clear(), g[i] = 0;
        if (kase > 1) printf("\n");
        scanf("%d", &n);
        set<int> color;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &a, &b);
            color.insert(a); color.insert(b);
            v[a].push_back(b); v[b].push_back(a);
            ++g[a], ++g[b];
            ++vis[a][b], ++vis[b][a];
        }
        bool flag = 0;
        for (auto it = color.begin(); it != color.end(); ++it)
        {
            if (g[*it] % 2)
            {
                flag = 1;
                break;
            }
        }
        printf("Case #%d\n", kase);
        if (flag) cout << "some beads may be lost\n";
        else
        {
            euler(*color.begin());
        }
    }
    return 0;
}
