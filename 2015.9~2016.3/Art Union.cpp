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
const int MAXN = 5e4 + 111;

int cost[MAXN][6];
int dp[MAXN][6];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &cost[i][j]);
            dp[i][j] = dp[i - 1][j] + cost[i][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[j][i] = max(dp[j][i - 1], dp[j - 1][i]) + cost[j][i];
        }
    }

    for (int i = 1; i <= m; ++i) {
        printf("%d", dp[i][n - 1]);
        if (i != m) putchar(' ');
        else putchar('\n');
    }
    return 0;
}
