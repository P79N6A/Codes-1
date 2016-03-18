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
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
const int MAXN = 1010;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
typedef long long ll;

char mp[6][6];
int n, m;
bool flag = 0;

bool dfs(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] == '.')
        {
            mp[x][y] = '*';
            bool sub = dfs(nx, ny);
            mp[x][y] = '.';
            if (sub) return false;
        }
    }
    return true;
}

int main() {
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> mp[i][j];
            }
        flag = 0;
        for (int i = 0; i < n && !flag; ++i)
            for (int j = 0; j < m && !flag; ++j)
            {
                if (mp[i][j] == '.' && dfs(i, j))
                {
                    flag = 1;
                    break;
                }
            }
        if (flag)
            cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
