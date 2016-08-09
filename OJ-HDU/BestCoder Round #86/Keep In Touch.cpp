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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 55;
const int mod = 998244353;

bool ok[MAXN][MAXN];
int a[MAXN];
int dp[MAXN][MAXN][MAXN][3];
vector<int> G[MAXN];

bool check(int i, int j, int k) {
    return ok[i][j] && ok[j][k] && ok[k][i];
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m, k, q, x, y, z;; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d%d", &n, &m, &k, &q);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), G[i].clear();
        memset(ok, 0, sizeof ok);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                if (abs(a[i] - a[j]) <= k) {
                    ok[i][j] = ok[j][i] = 1;
                }
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    if (check(i, j, k)) dp[i][j][k][0] = 1;
                    else dp[i][j][k][0] = 0;
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                for (int k = n; k >= 1; --k) {
                    for (int l = 0; l < G[k].size(); ++l) {
                        int v = G[k][l];
                        dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j][v][0]) % mod;
                    }
                    for (int l = 0; l < G[j].size(); ++l) {
                        int v = G[j][l];
                        dp[i][j][k][2] = (dp[i][j][k][2] + dp[i][v][k][1]) % mod;
                    }
                    if (!dp[i][j][k][0]) continue;
                    for (int l = 0; l < G[i].size(); ++l) {
                        int v = G[i][l];
                        dp[i][j][k][0] = (dp[i][j][k][0] + dp[v][j][k][2]) % mod;
                    }
                }
            }
        }
        while (q --) {
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", dp[x][y][z][0]);
        }
    }
    return 0;
}
