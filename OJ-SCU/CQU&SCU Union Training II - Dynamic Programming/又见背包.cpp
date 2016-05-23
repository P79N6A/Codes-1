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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

bool dp[MAXN];
ll a[200], m[200];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, k; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) scanf("%lld", a + i);
        for (int i = 0; i < n; ++i) scanf("%lld", m + i);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            ll judge = a[i] * m[i];
            if (judge >= k) {
                for (int j = a[i]; j <= k; ++j)
                    dp[j] |= dp[j - a[i]];
            }
            else {
                int t = 1;
                while (m[i] > t) {
                    int w = t * a[i];
                    m[i] -= t;
                    for (int j = k; j >= w; --j) dp[j] |= dp[j - w];
                    t *= 2;
                }
                int w = m[i] * a[i];
                for (int j = k; j >= w; --j) dp[j] |= dp[j - w];
            }
        }
        if (dp[k]) puts("yes");
        else puts("no");
    }
    return 0;
}
