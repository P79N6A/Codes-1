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

const int MAXN = 40;

int l, r, c, ans;
int dir[6][3] = {{0, 0, 1}, {0, 0, -1},
                 {0, 1, 0}, {0, -1, 0},
                 {1, 0, 0}, {-1, 0, 0}};
char mp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
struct N {
    int x, y, z, dep;
    N(int a, int b, int c, int d):x(a),y(b),z(c),dep(d){}
};

void bfs(int x, int y, int z) {
    queue<N> q;
    q.push(N(x,y,z,0));
    vis[x][y][z] = 1;
    bool flag = 1;
    while (q.size() && flag) {
        N cur = q.front(); q.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];
            int nz = cur.z + dir[i][2];
            if (0 <= nx && nx < l && 0 <= ny && ny < r && 0 <= nz && nz < c) {
                if (mp[nx][ny][nz] == '.' && !vis[nx][ny][nz]) {
                    q.push(N(nx, ny, nz, cur.dep + 1));
                    vis[nx][ny][nz] = 1;
                }
                else if (mp[nx][ny][nz] == 'E') {
                    ans = cur.dep + 1;
                    flag = 0;
                    break;
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
    ios::sync_with_stdio(0);
    while (cin >> l >> r >> c && (l | r | c)) {
        int sl, sr, sc;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> mp[i][j][k];
                    vis[i][j][k] = 0;
                    if (mp[i][j][k] == 'S') sl = i, sr = j, sc = k;
                }
            }
        }
        ans = -1;
        bfs(sl, sr, sc);
        if (ans == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
    return 0;
}
