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

const int MAXN = 1e6;
int x, lastx;
int mi[MAXN];


int main() {
    int n;
    while (~scanf("%d", &n))
    {
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            lastx = x;
            scanf("%d", &x);
            for (int j = 0; j <= k; ++j)
            {
                if (x < mi[j])
                {
                    mi[j] = x;
                    break;
                }
                else if (j == k)
                {
                    ++k;
                    mi[k] = x;
                    break;
                }
            }
        }
        printf("%d\n", k);
    }
    return 0;
}
