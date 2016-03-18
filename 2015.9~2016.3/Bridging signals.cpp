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
const int MAXN = 4e4 + 111;

int m[MAXN];
int dp[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase, n; scanf("%d", &kase);
    while (kase--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", m + i), dp[i] = INF;

        for (int i = 0; i < n; ++i) {
            int x = lower_bound(dp, dp + n, m[i]) - dp;
            dp[x] = m[i];
        }

        printf("%d\n", lower_bound(dp, dp + n, INF) - dp);
    }
    return 0;
}
