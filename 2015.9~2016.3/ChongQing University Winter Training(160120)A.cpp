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
const int MAXN = 5e3 + 111;

int a[MAXN], b[MAXN];
ll dp[2][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)){
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) dp[0][i] = abs(a[0] - b[i]);
    for (int i = 1; i < n; ++i) {
        int x = i % 2;
        ll mi = dp[1 - x][0];
        for (int j = 0; j < n; ++j) {
            mi = min(dp[1 - x][j], mi);
            dp[x][j] = mi + abs(a[i] - b[j]);
        }
    }
    ll ans = dp[(n - 1) % 2][0];
    for (int i = 1; i < n; ++i) ans = min(ans, dp[(n - 1) % 2][i]);
    printf("%I64d\n", ans);
    }
    return 0;
}
