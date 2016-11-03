#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;
const int MOD = 1e9 + 7;

ll u[MAXN], v[MAXN], w[MAXN];
// up[i][j][k]: 大于等于i的倍数的路线的个数
// 那么倍数的路线连在一起的答案肯定是以i为gcd
ll up[102][102][102];
ll path[102];
ll dp[102];
ll temp[102];
int n, m;

ll dfs(int s, int gcd) {
    if (dp[s] != -1) return dp[s];
    ll ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (up[gcd][s][i])
            ret = (ret + up[gcd][s][i] + up[gcd][s][i] * dfs(i, gcd)) % MOD;
    }
    return dp[s] = ret;
}

ll cal(int gcd) {
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) dfs(i, gcd);
    }
    ll ret = 0;
    for (int i = 1; i <= n; ++i) ret = (ret + dp[i]) % MOD;
    return ret;
}

inline void solve() {
    for (int i = 100; i > 0; --i) {
        temp[i] = path[i];
        for (int j = i * 2; j <= 100; j += i) {
            temp[i] -= temp[j];
        }
        temp[i] = (temp[i] % MOD + MOD) % MOD;
    }
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t, x, y;
    while (~scanf("%d%d", &n, &m)) {
        memset(up, 0, sizeof up);
        for (int i = 1; i <= m; ++i) {
            scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
            for (int j = 1; j * j <= w[i]; ++j) {
                if (w[i] % j == 0) {
                    ++up[j][u[i]][v[i]];
                    if (w[i] / j != j) ++up[w[i] / j][u[i]][v[i]];
                }
            }
        }
        for (int i = 1; i <= 100; ++i) {
            path[i] = cal(i);
        }
        solve();
        printf("%lld\n", temp[1]);
        scanf("%d", &t);
        while (t --) {
            scanf("%d%d", &x, &y);
            vector<int> G;
            for (int j = 1; j * j <= w[x]; ++j) {
                if (w[x] % j == 0) {
                    --up[j][u[x]][v[x]];
                    G.push_back(j);
                    if (w[x] / j != j) {
                        --up[w[x] / j][u[x]][v[x]];
                        G.push_back(w[x] / j);
                    }
                }
            }
            w[x] = y;
            for (int j = 1; j * j <= w[x]; ++j) {
                if (w[x] % j == 0) {
                    ++up[j][u[x]][v[x]];
                    G.push_back(j);
                    if (w[x] / j != j) {
                        ++up[w[x] / j][u[x]][v[x]];
                        G.push_back(w[x] / j);
                    }
                }
            }
            for (int i = 0; i < G.size(); ++i) {
                path[G[i]] = cal(G[i]);
            }
            solve();
            printf("%lld\n", temp[1]);
        }
    }
    return 0;
}