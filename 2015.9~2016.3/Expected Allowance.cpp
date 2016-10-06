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
const int MAXN = 1e4 + 111;

ll dp[25][MAXN];
int n, m, k;

void init() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        int up = i * m;
        for (int j = i; j <= up; ++j) {
            for (int k = max(1, j - m); k < j; ++k)
                dp[i][j] += dp[i - 1][k];
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d%d", &n, &m, &k) && (n | m | k)) {
        init();
        double ans = 0;
        int up = n * m;
        double d = pow(m, n);
        for (int i = n; i <= up; ++i) {
            ans += max(1, i - k) * dp[n][i] / d;
        }
        printf("%.8f\n", ans);
    }
    return 0;
}
