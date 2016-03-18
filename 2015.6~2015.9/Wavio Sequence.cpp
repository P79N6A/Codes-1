#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4 + 111;
int num[MAXN], inc[MAXN], de[MAXN], dp[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i) cin >> num[i], inc[i] = de[i] = 1;
        dp[0] = num[0];
        int len = 0;
        for (int i = 1; i < n; ++i)
        {
            if (num[i] > dp[len])
            {
                dp[++len] = num[i];
                inc[i] = len + 1;
            }
            else
            {
                int p = lower_bound(dp, dp + len, num[i]) - dp;
                dp[p] = num[i];
                inc[i] = p + 1;
            }
        }
        dp[0] = num[n - 1];
        len = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (num[i] > dp[len])
            {
                dp[++len] = num[i];
                de[i] = len + 1;
            }
            else
            {
                int p = lower_bound(dp, dp + len, num[i]) - dp;
                dp[p] = num[i];
                de[i] = p + 1;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, 2 * min(inc[i], de[i]) - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
