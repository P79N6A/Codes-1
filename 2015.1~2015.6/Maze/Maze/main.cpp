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
typedef long long ll;
using namespace std;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int MAXN = 510;
char mp[MAXN][MAXN];
bool flag[MAXN][MAXN];

struct node{
    int x, y;
};

queue<node> q;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%s", mp[i]);
    int need = n * m - k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mp[i][j] == '#')
                --need;
    
    for (int i = 0; i < n && q.empty(); ++i)
        for (int j = 0; j < m; ++j)
            if (mp[i][j] == '.')
            {
                q.push(node{i, j});
                break;
            }
    
    while (!q.empty())
    {
        node now = q.front(); q.pop();
        int x = now.x, y = now.y;
        if (flag[x][y])
            continue;
        flag[x][y] = 1;
        --need;
        if (need == 0)
            break;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !flag[nx][ny] && mp[nx][ny] == '.')
            {
                q.push(node{nx, ny});
            }
        }
    }
    for (int i = 0; i < n; ++i, putchar('\n'))
        for (int j = 0; j < m; ++j)
        {
            if (mp[i][j] == '.' && !flag[i][j])
                printf("X");
            else printf("%c", mp[i][j]);
        }
    return 0;
}
