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
const int MAXN = 1e3 + 111;

int dp[MAXN][2][MAXN];
int a[2][MAXN];
char mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> (mp[i] + 1);
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '#') ++a[0][j];
            else ++a[1][j];
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = dp[0][1][0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = x; k <= y; ++k)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j ^ 1][k] + a[j][i]);
            for (int k = 1; k <= y; ++k) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + a[j][i]);
            }
        }
    }
    int ans = INF;
    for (int i = x; i <= y; ++i) {
        ans = min(ans, min(dp[m][0][i], dp[m][1][i]));
    }
    cout << ans << '\n';
    return 0;
}
