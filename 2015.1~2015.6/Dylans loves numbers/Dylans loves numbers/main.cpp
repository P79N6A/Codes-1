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
const int MAXN = 1010;


int main() {
    int t; scanf("%d", &t);
    ll n;
    while (t --)
    {
        scanf("%lld", &n);
        int cnt = 0;
        int ans = 0;
        while (n)
        {
            if (n & 1)
            {
                ++cnt;
            }
            else {
                if (cnt)
                {
                    ++ans;
                    cnt = 0;
                }
            }
            n >>= 1;
        }
        if (cnt)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
