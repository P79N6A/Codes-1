#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define bug puts("I am bug")
#define xy(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;

const int MAXN = 1110;
int a[MAXN], cnt;
int res;
int dp[MAXN][MAXN];

int main() {
    int n, q, l, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] > a[j])
                dp[i][j] += dp[i][j - 1] + 1;
            else dp[i][j] = dp[i][j - 1];
        }
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        res = 0;
        for (int i = l; i <= r; ++i)
            res += dp[i][r];
        printf("%d\n", res);
    }
    return 0;
}
