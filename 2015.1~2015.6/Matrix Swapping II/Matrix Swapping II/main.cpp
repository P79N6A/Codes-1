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

const int MAXN = 1010;


int main() {
    int n, m;
    char s[MAXN];
    int h[MAXN], ht[MAXN];
    while (~scanf("%d %d", &n, &m))
    {
        memset(h, 0, sizeof h);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            for (int j = 0; j < m; ++j)
            {
                if (s[j] == '1')
                    ++h[j];
                else h[j] = 0;
                ht[j] = h[j];
            }
            sort(ht, ht + m);
            for (int j = 0; j < m; ++j)
            {
                int cnt = m - (lower_bound(ht, ht + m, h[j]) - ht);
                ans = max(ans, cnt * h[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
