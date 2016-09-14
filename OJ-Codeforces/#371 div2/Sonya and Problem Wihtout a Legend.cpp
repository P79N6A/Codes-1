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
const int MAXN = 3e3 + 111;

ll dp[MAXN][MAXN];
ll a[MAXN], b[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = (a[i] -= i);
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + abs(a[i] - b[1]);
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(a[i] - b[j]));
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
