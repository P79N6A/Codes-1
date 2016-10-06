#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 5e2 + 111;
int n, k;
bool vis[MAXN], line[MAXN][MAXN];
int match[MAXN];

bool fin(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (line[x][i] && !vis[i])
        {
            vis[i] = 1;
            if (!match[i] || fin(match[i]))
            {
                match[i] = x;
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
    while (cin >> n >> k)
    {
        memset(line, 0, sizeof line);
        memset(match, 0, sizeof match);
        int x, y;
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            line[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            memset(vis, 0, sizeof vis);
            if (fin(i)) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}

