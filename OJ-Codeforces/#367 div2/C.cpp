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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

string s[2][MAXN];
ll a[MAXN];
ll dp[MAXN][2];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> s[1][i];
        s[0][i] = s[1][i];
        reverse(s[1][i].begin(), s[1][i].end());
        dp[i][0] = dp[i][1] = 1e18;
    }
    dp[1][0] = 0, dp[1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        for (int k = 0; k < 2; ++k) {
            if (s[0][i] >= s[k][i - 1]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][k]);
            }
        }
        for (int k = 0; k < 2; ++k) {
            if (s[1][i] >= s[k][i - 1]) {
                dp[i][1] = min(dp[i][1], dp[i - 1][k] + a[i]);
            }
        }
    }
    if (dp[n][0] != 1e18 || dp[n][1] != 1e18) cout << min(dp[n][0], dp[n][1]) << '\n';
    else cout << -1 << '\n';
    return 0;
}
