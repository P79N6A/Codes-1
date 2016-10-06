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
#define BUG puts("I am bug")
#define XY(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const int MAXN = 2e5 + 111;

int mp[MAXN];
int mx[MAXN];
int dp[MAXN];

int main() {
    int m, n;
    while(~scanf("%d%d", &m, &n))
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                scanf("%d", &mp[j]);
            mp[1] = max(mp[0], mp[1]);
            for (int j = 2; j < n; ++j)
            {
                mp[j] = max(mp[j - 2] + mp[j], mp[j - 1]);
            }
            mx[i] = mp[n - 1];
        }
        for (int i = 0; i < m; ++i)
        {
            if (i >= 2)
                dp[i] = max(dp[i - 2] + mx[i], dp[i - 1]);
            else if (i == 1)
                dp[i] = max(mx[i], dp[i - 1]);
            else dp[i] = mx[i];
        }
        printf("%d\n", dp[m - 1]);
    }
    
    return 0;
}