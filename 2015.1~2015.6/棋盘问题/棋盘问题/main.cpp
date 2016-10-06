#include <iostream>
#include <cstring>
using namespace std;
char mp[10][10];
bool column[10];
bool row[10];
struct Node{
    int x, y;
}node[100];

int ans, cnt, k;

void dfs(int now, int cntt)
{
    if (cntt == cnt + 1)
        return;
    if (cntt == k)
    {
        ++ans;
        return;
    }
    for (int i = now; i < cnt; ++i)
    {
        struct Node& e = node[i];
        if (!column[e.x] && !row[e.y])
        {
            column[e.x] = 1, row[e.y] = 1;
            dfs(i + 1, cntt + 1);
            column[e.x] = 0, row[e.y] = 0;
        }
    }
}

int main() {
    int n;
    while (cin >> n >> k && n != -1 && k != -1)
    {
        memset(column, 0, sizeof column);
        memset(row, 0, sizeof row);
        cnt = 0, ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> mp[i][j];
                if (mp[i][j] == '#')
                {
                    node[cnt].x = i, node[cnt].y = j;
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < cnt; ++i)
        {
            struct Node& e = node[i];
            column[e.x] = 1;row[e.y] = 1;
            dfs(i + 1, 1);
            column[e.x] = 0;row[e.y] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}