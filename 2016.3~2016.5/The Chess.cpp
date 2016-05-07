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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 21;

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int dirm[8][2] = {-2, -2, -1, 1, 2, 2, 1, -1, -1, 1, 2, 2, 1, -1, -2, -2};
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, sx, sy;

int disC[MAXN][MAXN];
int disM[MAXN][MAXN];
int disP[MAXN][MAXN];

int ok(char c, int x, int y) {
    if (mp[x][y] == '.') return 1;
    else if (mp[x][y] != c) {
        bool flag = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] == '.') {
                flag = 1;
                break;
            }
        }
        if (mp[x][y] == 'M' && flag) {
            bool flag2 = 0;
            for (int i = 0; i < 8; ++i) {
                int nx = x + dirm[i][0], ny = y + dirm[i][1];
                int jx = x + dir[i / 2][0], jy = dir[i / 2][1];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] == '.' && mp[jx][jy] == '.') {
                    flag2 = 1;
                    break;
                }
            }
            flag = flag2;
        }
        if (flag) return 2;
        return -1;
    }
    else return 1;
}

void bfsC() {
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    q.push(pii(sx, sy));
    disC[sx][sy] = 0;
    vis[sx][sy] = 1;
    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.first, y = u.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            while (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && mp[nx][ny] != 'D') {
                vis[nx][ny] = 1;
                int judge = ok('C', nx, ny);
                if (judge == -1) {
                    continue;
                }
                disC[nx][ny] = disC[x][y] + judge;
                q.push(pii(nx, ny));
            }
        }
    }
}

void bfsM() {
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    q.push(pii(sx, sy));
    disM[sx][sy] = 0;
    vis[sx][sy] = 1;
    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.first, y = u.second;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dirm[i][0], ny = y + dirm[i][1];
            int jx = x + dir[i / 2][0], jy = dir[i / 2][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && mp[jx][jy] == '.') {
                vis[nx][ny] = 1;
                int judge = ok('M', nx, ny);
                if (judge == -1) continue;
                disM[nx][ny] = disM[x][y] + judge;
                q.push(pii(nx, ny));
            }
        }
    }
}

void bfsP() {
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    dis[sx][sy] = 0;
    vis[sx][sy] = 1;
    int cnt = 0;
    for (int i = sx; i < n; ++i) {
        if (mp[i][sy] == 'D') ++cnt;
        if (cnt > 1) break;
        if (cnt == 1)
    }
/*    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.first, y = u.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            while (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && mp[nx][ny] != 'D') {
                vis[nx][ny] = 1;
                int judge = ok('C', nx, ny);
                if (judge == -1) {
                    continue;
                }
                disC[nx][ny] = disC[x][y] + judge;
                q.push(pii(nx, ny));
            }
        }
    }*/
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j) {
                disC[i][j] = disM[i][j] = disP[i][j] = INF;
                if (mp[i][j] == 'S')
                    sx = i, sy = j;
            }
        }
        bfsC();
        bfsM();
        bfsP();
    }
    return 0;
}
