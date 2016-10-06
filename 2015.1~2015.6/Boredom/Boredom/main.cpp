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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const int MAXN = 1e5 + 11;

int num[MAXN];
ll dp[MAXN];
bool flag[MAXN];


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x; scanf("%d", &x);
        ++num[x];
    }
    dp[1] = num[1];
    for (int i = 2; i < MAXN; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + (ll)num[i] * i);
    }
    printf("%lld\n", dp[MAXN - 1]);
    return 0;
}
