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
#define pii pair<int, int>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

struct E {
    int u, v, w;
    bool operator <(const E &t)const {
        return w < t.w;
    }
}e[11000];

char mp[MAXN][MAXN];
int vis[MAXN][MAXN], p[MAXN], w, h, dis[MAXN][MAXN], ecnt;
int dir[2][4] = {-1, 1, 0, 0, 0, 0, 1, -1};

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void bfs(int x, int y) {
    queue<pii> q;
    memset(dis, -1, sizeof dis);
    dis[x][y] = 0;
    q.push(pii(x, y));
    while (q.size()) {
        pii cur = q.front(); q.pop();
        int cx = cur.first, cy = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dir[0][i], ny = cy + dir[1][i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && mp[nx][ny] != '#' && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[cx][cy] + 1;
                if (vis[nx][ny]) {
                    e[ecnt].u = vis[x][y];
                    e[ecnt].v = vis[nx][ny];
                    e[ecnt++].w = dis[nx][ny];
                }
                q.push(pii(nx, ny));
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int N; scanf("%d", &N);
    while (N --) {
        scanf("%d%d", &w, &h);
        gets(mp[0]);
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            gets(mp[i]);
            //printf("%s\n", mp[i]);
            for (int j = 0; j < w; ++j) {
                if (mp[i][j] == 'A' || mp[i][j] == 'S') {
                    vis[i][j] = ++cnt;
                    p[cnt] = cnt;
                }
                else vis[i][j] = 0;
            }
        }

        ecnt = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (vis[i][j]) {
                    bfs(i, j);
                    //cout << vis[i][j] << '-' << ecnt << '\n';
                    //cout << "+++++++++++++++++++++++++++++\n";
                }
            }
        }

        sort(e, e + ecnt);
        int ans = 0;
        for (int i = 0; i < ecnt; ++i) {
            int u = find(e[i].u), v = find(e[i].v);
            if (v != u) {
                p[u] = v;
                ans += e[i].w;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
