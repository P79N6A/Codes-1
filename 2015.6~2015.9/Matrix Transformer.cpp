#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 211;
int line[MAXN][MAXN], match[MAXN], n;
bool vis[MAXN];

bool find(int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (line[x][i] && !vis[i])
        {
            vis[i] = 1;
            if (match[i] == -1 || find(match[i]))
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
    while (cin >> n)
    {
        char x;
        memset(line, 0, sizeof line);
        memset(match, -1, sizeof match);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> x;
                if (x == 'U') line[i][j] = 1;
            }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            memset(vis, 0, sizeof vis);
            ans += find(i);
        }
        if (ans == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

