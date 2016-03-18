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

int imx[MAXN], sum[200], dp[MAXN];

int main()
{
    int n, m, k, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &sum[j]);
            sum[j] += sum[j - 1];
        }

        for (int j = 1; j <= k; ++j) {
            int l = 1, r = k - j;
            int mi = -INF;
            while (r <= k) {
                mi = max(mi, sum[k] - (sum[r] - sum[l - 1]));
                ++l, ++r;
            }
            imx[j] = mi;
        }

        for (int j = m; j >= 1; --j) {
            for (int l = 1; l <= k && j - l >= 0; ++l) {
                dp[j] = max(dp[j], dp[j - l] + imx[l]);
                ans = max(ans, dp[j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
