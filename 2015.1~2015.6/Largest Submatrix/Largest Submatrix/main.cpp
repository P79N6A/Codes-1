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
const int MAXN = 1110;

char s[MAXN][MAXN];
int l[MAXN], r[MAXN], h[MAXN];
int m, n, ans;

inline void judge(char a, char b, char c, char d)
{
    memset(h, 0, sizeof h);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s[i][j] == a || s[i][j] == b || s[i][j] == c || s[i][j] == d)
                ++h[j];
            else h[j] = 0;
            l[j] = r[j] = j;
        }
        for (int j = 0; j < n; ++j)
            while (l[j] >= 1 && h[j] <= h[l[j] - 1])
                l[j] = l[l[j] - 1];
        for (int j = n - 1; j >= 0; --j)
        {
            while (r[j] <= n - 2 && h[j] <= h[r[j] + 1])
                r[j] = r[r[j] + 1];
            ans = max(ans, h[j] * (r[j] - l[j] + 1));
        }
    }
}


int main() {
    while (~scanf("%d%d", &m, &n))
    {
        ans = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%s", s[i]);
        }
        judge('w', 'y', 'z', 'a');
        judge('w', 'x', 'z', 'b');
        judge('x', 'y', 'z', 'c');
        printf("%d\n", ans);
    }
    return 0;
}
