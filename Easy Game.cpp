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

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

int dp[MAXN][MAXN];
int a[MAXN], sum[MAXN];

int dfs(int l, int r) {
    int &ret = dp[l][r];
    if (ret > -INF) return ret;
    if (l == r) return ret = a[l];

    int s = sum[r] - sum[l - 1];
    ret = s; // 全拿的情况
    for (int i = 1; i <= r - l; ++i)
        ret = max(s - dfs(l + i, r), max(ret, s - dfs(l, r - i)));
    return ret;
}

int main()
{
    int kase, n; cin >> kase;
    for (int cas = 1; cas <= kase; ++cas) {
        cout << "Case " << cas << ": ";
        cin >> n;
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                dp[i][j] = -INF;

        cout << 2 * dfs(1, n) - sum[n] << '\n';
    }
    return 0;
}
