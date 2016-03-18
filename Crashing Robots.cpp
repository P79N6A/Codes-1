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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 211;

int mp[MAXN][MAXN];
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
map<char, int> id;
struct R {
    int x, y, dir;
}r[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    id['N'] = 0, id['E'] = 1, id['S'] = 2, id['W'] = 3;
    int kase; scanf("%d", &kase);
    while (kase --) {
        int a, b, n, m;
        char dir[2];
        scanf("%d%d", &a, &b);
        memset(mp, 0, sizeof mp);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %s", &r[i].x, &r[i].y, dir);
            mp[r[i].x][r[i].y] = i;
            r[i].dir = id[dir[0]];
        }

        bool flag = 0;
        int x, rep;
        char op[2];
        while (m --) {
            scanf("%d %s %d", &x, op, &rep);
            if (flag) continue;
            if (op[0] == 'L') {
                rep %= 4;
                r[x].dir = (r[x].dir - rep + 4) % 4;
            }
            else if (op[0] == 'R') {
                rep %= 4;
                r[x].dir = (r[x].dir + rep) % 4;
            }
            else {
                int sta = 0;
                mp[r[x].x][r[x].y] = 0;
                int nx = r[x].x, ny = r[x].y, op = r[x].dir;
                for (int i = 0; i < rep; ++i) {
                    nx += dirx[op];
                    ny += diry[op];
                    if (nx > a || nx < 1 || ny > b || ny < 1) {
                        sta = -1;
                        break;
                    }
                    if (mp[nx][ny]) {
                        sta = mp[nx][ny];
                        break;
                    }
                }

                if (sta == -1) {
                    flag = 1;
                    printf("Robot %d crashes into the wall\n", x);
                }
                else if (sta != 0) {
                    flag = 1;
                    printf("Robot %d crashes into robot %d\n", x, sta);
                }
                else {
                    mp[nx][ny] = x;
                    r[x].x = nx, r[x].y = ny;
                }
            }
        }

        if (!flag) printf("OK\n");
    }
    return 0;
}
