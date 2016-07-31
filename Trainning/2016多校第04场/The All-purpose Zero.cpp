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
const int MAXN = 1e5 + 111;

int a[MAXN], dp[MAXN];
bool is[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        memset(is, 0, sizeof is);
        scanf("%d", &n);
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] == 0) ++cnt, ++sum, is[i] = 1;
            else a[i] -= cnt, cnt = 0;
        }
        memset(dp, 0x3f, sizeof dp);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (is[i]) continue;
            int x = lower_bound(dp, dp + n, a[i]) - dp;
            dp[x] = a[i];
            ans = max(ans, x + 1);
        }
        printf("Case #%d: %d\n", kase, ans + sum);
    }
    return 0;
}
