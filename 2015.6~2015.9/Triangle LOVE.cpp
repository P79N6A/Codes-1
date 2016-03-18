#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 2e3 + 111;
vector<int> v[MAXN];
bool vis[MAXN];
int d[MAXN];

bool dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < v[u].size(); ++i)
    {
        int cur = v[u][i];
        if (vis[cur] && d[u] == d[cur] + 2) return 1;
        if (vis[cur]) continue;
        d[cur] = d[u] + 1;
        if (dfs(cur)) return 1;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t, kase = 0; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        getchar();
        char s[2015];
        for (int i = 0; i < n; ++i)
        {
            v[i].clear();
            gets(s);
            for (int j = 0; s[j]; ++j)
            {
                if (s[j] == '1')
                    v[i].push_back(j);
            }
        }
        bool flag = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i)
        {
            d[i] = 0;
            if (dfs(i))
            {
                flag = 1;
                break;
            }
        }
        printf("Case #%d: ", ++kase);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
