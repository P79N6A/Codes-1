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
const double eps = 0.00000000000000000000001;
typedef long long ll;

int main() {
    char c;
    int a[9];
    
    int t; scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i)
    {
        for (int j = 0; j < 9; ++j)
            a[j] = 0;
        while ((c = getchar()) != '\n')
        {
            if (c == 'g')
                ++a[0];
            if (c == 'o')
                ++a[1];
            if (c == 'r')
                ++a[2];
            if (c == 'i')
                ++a[3];
            if (c == ' ')
                ++a[4];
            if (c == 'd')
                ++a[5];
            if (c == 'm')
                ++a[6];
            if (c == 'n')
                ++a[7];
        }
        //for (int i = 0; i <= 7; ++i) cout << a[i] << endl;
        int ans = 10000;
        for (int j = 2; j <= 6; ++j)
            if (ans > a[j])
                ans = a[j];
        a[0] -= 1;
        if (ans > a[0])
            ans = a[0];
        if (ans > a[1] / 3)
            ans = a[1] / 3;
        if (ans > a[7] / 2)
            ans = a[7] / 2;
        if (a[0] < 0)
            ans = 0;
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}