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
using namespace std;
typedef long long ll;

int l[15], r[15];
bool vis[15];
int ans, n;

void dfs(int first, int dep, int last)
{
    if (dep == n)
    {
        if (__gcd(l[first], r[last]) == 1)
            ++ans;
        else return;
    }
    for (int i = 1; i < n; ++i)
    {
        if (!vis[i])
        {
            if (__gcd(l[i], r[last]) == 1)
            {
                vis[i] = 1;
                dfs(0, dep + 1, i);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    while (~scanf("%d", &n))
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", l + i, r + i);
        ans = 0;
        if (n != 1) dfs(0, 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
