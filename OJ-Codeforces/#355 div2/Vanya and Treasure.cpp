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

const int INF = 0x3f3f3f3f;
const int MAXN = 311;

struct Pt {
    int x, y;
};
int dp[MAXN][MAXN], dis[MAXN][MAXN];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool vis[MAXN][MAXN];
vector<Pt> G[MAXN * MAXN];

int getdis(Pt &a, Pt &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool in_range(int &x, int &y) {
    return (x >= 0 && x < y);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, p, x;
    while (~scanf("%d%d%d", &n, &m, &p)) {
        for (int i = 1; i <= p; ++i) G[i].clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &x);
                G[x].push_back(Pt{i, j});
                dp[i][j] = (x == 1 ? i + j : INF);
            }
        }
        for (int k = 1; k < p; ++k) {
            int cnt = G[k].size(), cnt2 = G[k + 1].size();
            if (cnt * cnt2 <= n * m) {
                for (int i = 0; i < cnt; ++i) {
                    Pt &u = G[k][i];
                    for (int j = 0; j < cnt2; ++j) {
                        Pt &v = G[k + 1][j];
                        dp[v.x][v.y] = min(dp[v.x][v.y], dp[u.x][u.y] + getdis(u, v));
                    }
                }
            }
            else {
                memset(dis, 0x3f, sizeof dis);
                memset(vis, 0, sizeof vis);
                queue<Pt> q;
                for (int i = 0; i < cnt; ++i) {
                    Pt u = G[k][i];
                    q.push(u);
                    dis[u.x][u.y] = dp[u.x][u.y];
                    vis[u.x][u.y] = 1;
                }

                while (q.size()) {
                    Pt u = q.front(), v; q.pop();
                    vis[u.x][u.y] = 0;
                    for (int i = 0; i < 4; ++i) {
                        v.x = u.x + dir[i][0], v.y = u.y + dir[i][1];
                        if (in_range(v.x, n) && in_range(v.y, m)) {
                            if (dis[v.x][v.y] > dis[u.x][u.y] + 1) {
                                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                                if (!vis[v.x][v.y]) {
                                    vis[v.x][v.y] = 1;
                                    q.push(v);
                                }
                            }
                        }
                    }
                }

                for (int i = 0; i < cnt2; ++i) {
                    Pt &u = G[k + 1][i];
                    dp[u.x][u.y] = dis[u.x][u.y];
                }
            }
        }
        printf("%d\n", dp[G[p][0].x][G[p][0].y]);
    }
    return 0;
}
