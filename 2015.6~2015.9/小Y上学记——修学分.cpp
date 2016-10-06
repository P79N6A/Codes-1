#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 111;
int vis[MAXN], topo[MAXN], g[MAXN], n, m, k; //g:入度
vector<int> v[MAXN];

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        for (int i = 0; i < n; ++i) v[i].clear();
        memset(g, 0, sizeof g);
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            ++g[b];
        }
        memset(vis, 0, sizeof vis);
        vector<int> ans;
        while (1)
        {
            bool flag = 1;
            for (int i = 0; i < n; ++i)
            {
                if (!vis[i] && g[i] == 0)
                {
                    flag = 0;
                    vis[i] = 1;
                    ans.push_back(i);
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        int cur = v[i][j];
                        --g[cur];
                    }
                    break; //更新完记得break掉
                }
            }
            if (flag) break;
        }
        if (ans.size() >= k)
        {
            for (int i = 0; i < k; ++i)
            {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}
