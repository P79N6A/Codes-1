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
const int MAXN = 1e5 + 111;

int y[MAXN];

int main() {
    int n, t; scanf("%d %d", &n, &t);
    y[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &y[i]);
        y[i] += y[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        int l = i, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (y[mid] - y[i] <= t)
                l = mid + 1;
            else r = mid;
        }
        if (y[l] - y[i] > t)
            l -= 1;
        ans = max(ans, l - i);
    }
    printf("%d\n", ans);
    return 0;
}
