#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 111;

char mp[MAXN][MAXN];
int dis[MAXN][MAXN];
int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
int block[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int sx, sy, ex, ey;
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 's') sx = i, sy = j;
                if (mp[i][j] == 'e') ex = i, ey = j;
            }
        }
        memset(dis, 0x3f, sizeof dis);
        queue<pii> q;
        q.push(pii(sx, sy));
        dis[sx][sy] = 0;
        while (q.size()) {
            pii cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
           // printf("%d %d - > \n", x, y);
            for (int i = 0; i < 8; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                //printf("%d %d\n", nx, ny);
                if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] != '#' && mp[x + block[i/2][0]][y + block[i/2][1]] != '#') {
                    if (dis[nx][ny] > dis[x][y] + 1) {
                        //pr("go")
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push(pii(nx, ny));
                    }
                }
            }
        }
        if (dis[ex][ey] == 0x3f3f3f3f) dis[ex][ey] = -1;
        printf("%d\n", dis[ex][ey]);
    }
    return 0;
}
