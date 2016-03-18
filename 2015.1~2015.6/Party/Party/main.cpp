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
const int MAXN = 2110;

int p[MAXN];

int dfs(int x, int dep)
{
    int ret = 0;
    if (p[x] != -1)
        ret += dfs(p[x], dep + 1);
    else ret = dep;
    return ret;
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", p + i);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dfs(i, 1));
    printf("%d\n", ans);
    return 0;
}
