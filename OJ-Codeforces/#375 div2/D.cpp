#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 61;

string s[MAXN];
int vis[MAXN][MAXN];
int scc = 0;
struct P {
    int id, num, is;
    bool operator < (const P&t) const {
        return num < t.num;
    }
}p[MAXN * MAXN];

int n, m, k;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int dfs(int x, int y) {
    vis[x][y] = scc;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (s[nx][ny] == '.' && vis[nx][ny] == -1) {
                ret += dfs(nx, ny);
            }
        }
        else {
            p[scc].is = 0;
        }
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    memset(vis, -1, sizeof vis);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.' && vis[i][j] == -1) {
                p[scc].is = 1;
                p[scc].num = dfs(i, j);
                p[scc].id = scc;
                if (p[scc].is) {
                    ++ans;
                }
                ++scc;
            }
        }
    }
    sort(p, p + scc);
    int i = 0, cnt = 0;
    while (ans > k) {
        for (; i < scc; ++i) {
            if (p[i].is) {
                --ans;
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < m; ++k) {
                        if (vis[j][k] == p[i].id) {
                            s[j][k] = '*';
                            ++cnt;
                        }
                    }
                }
                ++i;
                break;
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i) cout << s[i] << '\n';
    return 0;
}
