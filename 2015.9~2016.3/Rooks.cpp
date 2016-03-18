#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

bool vis[MAXN];
int n, deg[MAXN], ans, cnt, mp[MAXN][MAXN], link[MAXN];
string s[MAXN];
vector<vector<int> > G;

void init()
{
    memset(deg, 0, sizeof(int) * (n + 2));
    memset(vis, -1, sizeof(int) * (n + 2));
    G.clear();
    G.resize(n + 2);
    ans = 0;
}

bool find(int x)
{
    for (int i = 0; i < G[x].size(); ++i) if (!vis[G[x][i]])
    {
        int y = G[x][i];
        vis[y] = 1;
        if (link[y] == -1 || find(link[y]))
        {
            link[y] = x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T --)
    {
        cin >> n;
        init();

        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
            cnt = 0;
            for (int j = 0; j < n; ++j)
            {
                mp[i][j] = 0;
                if (s[i][j] == '*')
                {
                    G[i].push_back(j);
                    ++cnt; ++deg[j];
                }
            }
            ans = max(ans, cnt);
        }

        for (int i = 0; i < n; ++i)
        {
            cnt = 0;
            for (int j = 0; j < n; ++j) if (s[j][i] == '*')
                ++cnt;
            ans = max(ans, cnt);
        }

        // 补全二分图，防止失配
        for (int i = 0; i < n; ++i) if (G[i].size() < ans)
        {
            for (int j = 0; j < n && G[i].size() < ans; ++j) if (deg[j] < ans)
            {
                while(deg[j] < ans && G[i].size() < ans)
                {
                    G[i].push_back(j);
                    ++deg[j];
                }
            }
        }

        /*for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < G[i].size(); ++j)
                cout << G[i][j] << ' ';
            cout << '\n';
        }*/

        cout << ans << '\n';
        int color = 0;
        while (color < ans)
        {
            ++color;
            memset(link, -1, sizeof(int) * (n + 2));
            for (int i = 0; i < n; ++i)
            {
                memset(vis, 0, sizeof(bool) * (n + 2));
                find(i);
            }

            for (int i = 0; i < n; ++i)
            {
                int r = link[i], c = i;
                if (s[r][c] == '*') mp[r][c] = color;
                // 已经匹配好的点就不要再动它了
                for (int j = 0; j < G[r].size(); ++j) if (G[r][j] == c)
                {
                    G[r].erase(G[r].begin() + j);
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i, cout << '\n')
        {
            for (int j = 0; j < n; ++j)
            {
                cout << mp[i][j];
                if (j != n) cout << ' ';
            }
        }
    }
    return 0;
}
