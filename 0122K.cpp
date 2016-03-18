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
const int MAXN = 1e5 + 111;

int a[MAXN], dp[MAXN];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int lans = 0;
    for (int i = 0; i < n; ++i) {
        int ans = dp[a[i]];
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                ans = max(max(ans, dp[j]), dp[a[i] / j]);
            }
        }
        ++ans;
        lans = max(lans, ans);
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                dp[j] = dp[a[i] / j] = ans;
            }
        }
        dp[a[i]] = ans;
    }
    printf("%d\n", lans);
    return 0;
}
