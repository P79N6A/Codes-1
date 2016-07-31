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

int dp[MAXN][MAXN];
int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), dp[i][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (i > 2) dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + max(a[i - 1], a[i - 2]));
            if (i > 1 && i + 1 <= n) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + max(a[i - 1], a[i + 1]));
            if (j - 2 >= 0 && i + 2 <= n) dp[i][j] = min(dp[i][j], dp[i][j - 2] + max(a[i + 1], a[i + 2]));
            //if (i == 1) printf("dp[1][%d] = %d\n", j, dp[i][j]);
        }
    }
    int ans = 0;
    printf("%d\n", ans);
    return 0;
}
