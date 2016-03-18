#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
const int MAXN = 1010;
typedef long long ll;

int mp[8][MAXN];

int main() {
    int n;
    while (~scanf("%d", &n))
    {
        getchar();
        memset(mp, 0, sizeof mp);
        char a[8];
        n = 2 * n - 1;
        for (int i = 0; i < n; ++i)
        {
            gets(a);
            for (int j = 0; j < 7; ++j)
            {
                ++mp[j][a[j]];
            }
        }
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < MAXN; ++j)
            {
                if (mp[i][j] % 2)
                {
                    printf("%c",j);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}