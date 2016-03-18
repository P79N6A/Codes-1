#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define BUG puts(“I am here!”)
using namespace std;
const int MAXN = 1e3 + 11;
typedef long long ll;

char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dir[2][8] = {{-1, -2, -2, -1, 1, 2, 2, 1}, {-2, -1, 1, 2, 2, 1, -1, -2}};

int k, x, y;
int n, m, cnt = 0;

void make(char a)
{
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &x, &y);
        mp[x][y] = a;
        vis[x][y] = 1;
    }
}

void mark_k(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dir[0][i], ny = y + dir[1][i];
        if (0 < nx && nx <= n && 0 < ny && ny <= m && mp[nx][ny] == '#')
        {
            vis[nx][ny] = 1;
            //printf("(%d,%d)\n", nx, ny);
        }
    }
}

void mark_q(int x, int y)
{
    for (int i = 1; ; ++i)
    {
        int ny = y + i;
        if (mp[x][ny] == '#' && ny <= m)
            vis[x][ny] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int ny = y - i;
        if (mp[x][ny] == '#' && ny > 0)
            vis[x][ny] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x + i;
        if (mp[nx][y] == '#' && nx <= n)
            vis[nx][y] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x - i;
        if (mp[nx][y] == '#' && nx > 0)
            vis[nx][y] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x + i, ny = y + i;
        if (mp[nx][ny] == '#' && 0 < nx && nx <= n && 0 < ny && ny <= m)
            vis[nx][ny] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x - i, ny = y - i;
        if (mp[nx][ny] == '#' && 0 < nx && nx <= n && 0 < ny && ny <= m)
            vis[nx][ny] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x + i, ny = y - i;
        if (mp[nx][ny] == '#' && 0 < nx && nx <= n && 0 < ny && ny <= m)
            vis[nx][ny] = 1;
        else break;
    }
    for (int i = 1; ; ++i)
    {
        int nx = x - i, ny = y + i;
        if (mp[nx][ny] == '#' && 0 < nx && nx <= n && 0 < ny && ny <= m)
            vis[nx][ny] = 1;
        else break;
    }
}

int main() {
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0))
    {
        memset(mp, '#', sizeof mp);
        memset(vis, 0, sizeof vis);
        make('Q'), make('K'), make('P');
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (mp[i][j] == 'K')
                    mark_k(i, j);
                if (mp[i][j] == 'Q')
                    mark_q(i, j);
            }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!vis[i][j])
                    ++ans;
        printf("Board %d has %d safe squares.\n", ++cnt, ans);
    }
    
    return 0;
}
