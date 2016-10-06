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
#define pr(x) cout << #x << " = " << (x) << "; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e3 + 11;

int n, m, q;
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];

inline void init(int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + i, ny = y + j;
            if (0 < nx && nx <= n && 0 < ny && ny <= m) {
                dis[x][y] = max(dis[x][y], dis[nx][ny] - abs(i) - abs(j));
            }
        }
    }
}

bool solve(int x, int y) {
    if (!vis[x][y]) {
        vis[x][y] = 1;
        printf("%d %d\n", x, y);
        return 1;
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int x, y;
    scanf("%d%d%d", &n, &m, &q);
    while (q --) {
        scanf("%d%d", &x, &y);
        if (!vis[x][y]) {
            printf("%d %d\n", x, y);
            vis[x][y] = dis[x][y] = 1;
        }
        else {
            init(x, y);
            bool ok = 0;
            for (int &d = dis[x][y]; ; ++d) {
                for (int nx = x - d, dy = 0; nx <= x; ++nx, ++dy) {
                    if (nx < 1) continue;
                    int l = y - dy, r = y + dy;
                    if ((l > 0 && solve(nx, l)) || (r <= m && solve(nx, r))) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) break;
                for (int nx = x + 1, dy = d - 1; nx <= x + d; ++nx, --dy) {
                    if (nx > n) continue;
                    int l = y - dy, r = y + dy;
                    if ((l > 0 && solve(nx, l)) || (r <= m && solve(nx, r))) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) break;
            }
        }
    }
    return 0;
}
