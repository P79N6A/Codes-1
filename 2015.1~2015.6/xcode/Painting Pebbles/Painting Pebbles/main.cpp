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
const int MAXN = 110;
int a[MAXN];


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int mi = 1000, mx = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mi)
            mi = a[i];
    }
    if (mx - mi > k)
        printf("NO\n");
    else{
        printf("YES\n");
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < a[i]; ++j)
            {
                ++cnt;
                if (cnt > k)
                    cnt = 1;
                printf("%d", cnt);
                if (j != a[i] - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}