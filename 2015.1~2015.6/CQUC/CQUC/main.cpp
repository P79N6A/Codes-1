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
const int MAXN = 1010;
typedef long long ll;
ll xto[MAXN], yto[MAXN], zto[MAXN];

int main() {
    char s[10];
    ll x, y, z;
    while (~scanf("%s", s))
    {
        if (s[2] == 'L')
        {
            printf("START\n");
            scanf("%lld%lld%lld", &x, &y, &z);
            for (int i = 0; i <= MAXN; ++i)
            {
                xto[i] = yto[i] = zto[i] = i;
            }
        }
        else if (s[2] == 'A')
        {
            ll a, b;
            scanf("%lld%lld",&a, &b);
            if (s[4] == '1')
            {
                xto[a] = b;
                xto[b] = a;
            }
            else if (s[4] == '2')
            {
                yto[a] = b;
                yto[b] = a;
            }
            else {
                zto[a] = b;
                zto[b] = a;
            }
        }
        else if (s[2] == 'N')
        {
            ll f;
            scanf("%lld", &f);
            if (f > x * y * z)
                continue;
            else{
                ll fx, fy, fz;
                f--;
                fx = f / y / z;
                fz = f % z;
                fy = f % (y * z) / z;
                printf("%lld %lld %lld\n", xto[fx], yto[fy], zto[fz]);
            }
        }
        else if (s[2] == 'E')
        {
            int qx, qy, qz;
            scanf("%d%d%d",&qx, &qy, &qz);
            printf("%lld\n", xto[qx] * y * z + yto[qy] * z + zto[qz] + 1);
        }
            
    }
    return 0;
}
