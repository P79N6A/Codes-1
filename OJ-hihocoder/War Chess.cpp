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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 1044266559;
const int MAXN = 105;

int occupy[MAXN][MAXN];
struct Role {
    int hp, ak, mv;
    int akl, akr;
    int x, y;
    int group, last;
    void read() {
        scanf("%d%d%d%d%d%d%d%d", &hp, &ak, &mv, &akl, &akr, &x, &y, &group);
        occupy[x][y] = group;
    }
}role[MAXN];
int n, m, c, e, cnt;
int dis[MAXN][MAXN], mp[MAXN][MAXN];
char op[10], s[12];
int rnd, cur, x, y, who;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool checkAttack() {
    Role &u = role[who], &v = role[cur];
    int d = abs(u.x - v.x) + abs(u.y - v.y);
    if (u.hp <= 0 || u.group == rnd || d < v.akl || d > v.akr) return 1;
    return 0;
}

bool in[MAXN][MAXN];
inline void spfa() {
    memset(dis, -0x3f, sizeof dis);
    memset(in, 0, sizeof in);
    Role &r = role[cur];
    dis[r.x][r.y] = r.mv;
    in[r.x][r.y] = 1;
    queue<pii> q;
    q.push(pii(r.x, r.y));
    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.first, y = u.second;
        in[x][y] = false;
        if (dis[x][y] <= 0) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && occupy[nx][ny] != 1 - rnd) {
                if (dis[nx][ny] < dis[x][y] - mp[nx][ny]) {
                    dis[nx][ny] = dis[x][y] - mp[nx][ny];
                    if (dis[nx][ny] <= 0) continue;
                    for (int j = 0; j < 4; ++j) {
                        int nnx = nx + dir[j][0], nny = ny + dir[j][1];
                        if (1 <= nnx && nnx <= n && 1 <= nny && nny <= m && occupy[nnx][nny] == 1 - rnd) {
                            dis[nx][ny] = 0;
                            break;
                        }
                    }
                    if (!in[nx][ny]) {
                        in[nx][ny] = true;
                        q.push(pii(nx, ny));
                    }
                }
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d%d%d", &n, &m, &c, &e)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &mp[i][j]);
                occupy[i][j] = -1;
            }
        }
        for (int i = 1; i <= c; ++i) {
            role[i].read();
        }
        while (e --) {
            scanf("%s", op);
            if (op[0] == 'R') {
                scanf("%s%d", op, &rnd);
            }
            else if (op[0] == 'A' && op[1] == 'c') {
                scanf("%s%s%d", op, s, &cur);
            }
            else if (op[0] == 'A') {
                scanf("%d", &who);
                if (checkAttack() || role[who].hp - role[cur].ak <= 0) puts("INVALID");
                else {
                    printf("%d\n", role[who].hp -= role[cur].ak);
                }
            }
            else if (op[0] == 'M') {
                scanf("%s (%d,%d)", s, &x, &y);
                spfa();
                //prln(dis[x][y])
                if ((x == role[cur].x && y == role[cur].y) || (dis[x][y] >= 0 && occupy[x][y] == -1)) {
                    for (int i = 0; i < 4; ++i) {
                        int nx = x + dir[i][0], ny = y + dir[i][1];
                        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && occupy[nx][ny] == 1 - rnd) {
                            dis[x][y] = 0;
                            break;
                        }
                    }
                    printf("%d\n", dis[x][y]);
                    occupy[role[cur].x][role[cur].y] = -1;
                    occupy[x][y] = rnd;
                    role[cur].x = x, role[cur].y = y;
                }
                else {
                    puts("INVALID");
                }
            }
            else {
                scanf("%s %d", s, &who);
                if (checkAttack() || role[who].hp - role[cur].ak > 0) puts("INVALID");
                else {
                    printf("%d\n", role[who].hp -= role[cur].ak);
                    occupy[role[who].x][role[who].y] = -1;
                }
            }
        }
    }
    return 0;
}
