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
const int MAXN = 311;

int dp[MAXN << 1][MAXN][MAXN];
int mp[MAXN][MAXN];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
        }
    }

    int add;
    memset(dp, -0x7f, sizeof dp);
    dp[0][1][1] = mp[1][1];
    for (int i = 1; i <= n + n - 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (k == j) add = mp[j][i - j + 2];
                else add = mp[j][i - j + 2] + mp[k][i - k + 2];
                dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i - 1][j - 1][k - 1]),
                                  max(dp[i - 1][j - 1][k], dp[i - 1][j][k - 1])) + add;
            }
        }
    }
    cout << dp[2 * n - 2][n][n] << '\n';
    return 0;
}
