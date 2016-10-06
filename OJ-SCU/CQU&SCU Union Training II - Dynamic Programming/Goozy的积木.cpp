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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 111;

int dp[2][MAXN], a[100];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        memset(dp, -0x3f, sizeof dp);
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                int cur = i % 2;
                int opp = 1 - cur;
                dp[cur][j] = dp[opp][j];
                if (j > a[i]) {
                    dp[cur][j] = max(max(dp[cur][j], dp[opp][j - a[i]]), dp[opp][j + a[i]] + a[i]);
                }
                else
                    dp[cur][j] = max(max(dp[cur][j], dp[opp][a[i] - j] + a[i] - j), dp[opp][j + a[i]] + a[i]);
            }
        }
        int cur = n % 2;
        if (dp[cur][0])
            printf("%d\n", dp[cur][0]);
        else printf("GG\n");
    }
    return 0;
}
