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
const int MAXN = 41;

bool vis[MAXN][MAXN];
int mp[MAXN][MAXN], w, h, sx, sy, ans;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(int x, int y, int dirx, int diry, int dep) {
    //pr(x);pr(y);pr(dirx);pr(diry);pr(dep);
    if (dep >= ans) return;
    int nx = x, ny = y;
    while (1) {
        nx += dirx, ny += diry;
        if (0 <= nx && nx < h && 0 <= ny && ny < w) {
            if (mp[nx][ny] == 1 && !vis[nx][ny]) {
                nx -= dirx, ny -= diry;
                if (nx == x && ny == y) return;
                vis[nx + dirx][ny + diry] = 1;
                for (int i = 0; i < 4; ++i) {
                    dfs(nx, ny, dir[i][0], dir[i][1], dep + 1);
                }
                vis[nx + dirx][ny + diry] = 0;
                return;
            }
            else if (mp[nx][ny] == 3) {
                ans = min(ans, dep);
            }
        }
        else return;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &w, &h) && (w | h)) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                scanf("%d", &mp[i][j]);
                if (mp[i][j] == 2) sx = i, sy = j;
            }

        ans = 11;
        for (int i = 0; i < 4; ++i) {
            memset(vis, 0, sizeof vis);
            dfs(sx, sy, dir[i][0], dir[i][1], 1);
        }
        if (ans > 10) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
