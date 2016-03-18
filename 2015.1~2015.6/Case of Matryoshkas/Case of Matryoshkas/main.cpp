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

const int MAXN = 1e5 + 111;

int p[MAXN];
int ran[MAXN];

int f(int x)
{
    int res = 0;
    if (p[x] == 0)
        res += ran[p[x]];
    else
        res += f(p[x]) + ran[p[x]];
    ran[p[x]] = 0;
    p[x] = 0;
    return res;
}

int main() {
    int n, k, m; scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &m);
        int child = 0, pa;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &pa);
            if (child != 0)
                ran[pa] = 1;
            p[child] = pa;
            child = pa;
        }
    }
    //for (int i = 1; i <= n; ++i) cout << ran[i] << endl;
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (p[i] == i + 1)
            continue;
        else
            ans += f(i);
    }
    //cout << ans << endl;
    for (int i = 1; i < n; ++i)
    {
        if (p[i] == 0)
        {
            if (p[i + 1] == 0)
                ++ans;
            else ans += f(i + 1) + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
