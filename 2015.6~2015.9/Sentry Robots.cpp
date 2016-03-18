#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e3 + 555;
int n, m, k, x, a[111][111], row[111][111], col[111][111], match[MAXN];
//a[i][j] = 1:重要点  2:障碍
vector<int> G[MAXN];
bool vis[MAXN];

bool find(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (match[v] == -1 || find(match[v]))
            {
                match[v] = u;
                return 1;
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
    int t; cin >> t;
    while (t --)
    {
        cin >> n >> m;
        memset(a, 0, sizeof a);
        for (int sta = 1; sta <= 2; ++sta)
        {
            cin >> k;
            for (int i = 1; i <= k; ++i)
            {
                int u, v;
                cin >> u >> v;
                a[u][v] = sta;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            bool inc = 1;
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] == 1)
                {
                    if (inc) ++cnt;
                    row[i][j] = cnt; //给区域标号
                    inc = 0;
                }
                if (a[i][j] == 2) inc = 1;
            }
        }
        x = cnt;

        cnt = 0;
        for(int j = 1; j <= m; ++j)
        {
            bool inc = 1;
            for(int i = 1; i <= n; ++i)
            {
                if(a[i][j] == 1)
                {
                    if(inc) ++cnt;
                    col[i][j] = cnt; //同理 ↑
                    inc = 0;
                }
                if(a[i][j] == 2) inc = 1;
            }
        }

        for (int i = 1; i <= x; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] == 1)
                {
                    int u = row[i][j], v = col[i][j];
                    G[u].push_back(v); //行标号，列标号相连
                }
            }
        int ans = 0;
        memset(match, -1, sizeof match);
        for (int i = 1; i <= x; ++i)
        {
            memset(vis, 0, sizeof vis);
            ans += find(i);
        }
        cout << ans << '\n';
    }
    return 0;
}

