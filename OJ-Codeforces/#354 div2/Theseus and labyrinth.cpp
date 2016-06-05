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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 11;

int n, m;
int sx, sy, ex, ey, ans = -1;
char mp[MAXN][MAXN];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool vis[MAXN][MAXN][4];
bool ok[MAXN][MAXN][4];

struct P {
    int x, y, sta, dis;
    P(int a, int b, int c, int d): x(a), y(b), sta(c), dis(d){}
};

void bfs() {
    queue<P> q;
    q.push(P(sx, sy, 0, 0));
    vis[sx][sy][0] = 1;
    while (q.size()) {
        P u = q.front(); q.pop();
        int x = u.x, y = u.y, dis = u.dis, sta = u.sta;
        if (x == ex && y == ey) {
            ans = dis;
            return;
        }
        //printf("%d %d %d\n", x, y, sta);
        if (!vis[x][y][(sta + 1) % 4]) {
            vis[x][y][(sta + 1) % 4] = 1;
            q.push(P(x, y, (sta + 1) % 4, dis + 1));
        }

        for (int i = 0; i < 4; ++i) {
            if (ok[x][y][(i - sta + 4) % 4]) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if (ok[nx][ny][(i - sta + 6) % 4] && !vis[nx][ny][sta]) {
                    vis[nx][ny][sta] = 1;
                    q.push(P(nx, ny, sta, dis + 1));
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", mp[i] + 1);
        for (int j = 1; j <= m; ++j) {
            switch(mp[i][j]) {
                case '+':
                    ok[i][j][0] = ok[i][j][1] = ok[i][j][2] = ok[i][j][3] = 1; break;
                case '-':
                    ok[i][j][1] = ok[i][j][3] = 1; break;
                case '|':
                    ok[i][j][0] = ok[i][j][2] = 1; break;
                case '^':
                    ok[i][j][0] = 1; break;
                case '>':
                    ok[i][j][1] = 1; break;
                case 'v':
                    ok[i][j][2] = 1; break;
                case '<':
                    ok[i][j][3] = 1; break;
                case 'L':
                    ok[i][j][0] = ok[i][j][1] = ok[i][j][2] = 1; break;
                case 'R':
                    ok[i][j][0] = ok[i][j][2] = ok[i][j][3] = 1; break;
                case 'U':
                    ok[i][j][1] = ok[i][j][2] = ok[i][j][3] = 1; break;
                case 'D':
                    ok[i][j][0] = ok[i][j][1] = ok[i][j][3] = 1; break;
                default:
                    break;
            }
        }
    }
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    bfs();
    printf("%d\n", ans);
    return 0;
}
