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

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int MAXN = 1010;

int a[MAXN];


int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    int sub = -a[0];
    bool flag = 1;
    for (int i = 0; i < n && flag; ++i)
    {
        a[i] += sub;
        sub = -sub;
        if (a[i] >= 0)
            a[i] %= n;
        else a[i] += n;
        if (a[i] != i)
        {
            flag = 0;
            printf("No\n");
        }
    }
    if (flag)
        printf("Yes\n");
    return 0;
}
