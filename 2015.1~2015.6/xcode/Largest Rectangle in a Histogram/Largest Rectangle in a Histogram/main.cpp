#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100110;
typedef long long ll;

ll l[MAXN], r[MAXN], h[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld",&h[i]);
            l[i] = r[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            while (l[i] >= 2 && h[l[i] - 1] >= h[i]) //i板能到达的最左边
                l[i] = l[l[i] - 1];
        }
        ll ans = 0, tem = 0;
        for (int i = n; i >= 1; --i)//注意循环方向
        {
            while (r[i] <= n - 1 && h[r[i] + 1] >= h[i]) //i板能到达的最右边
                r[i] = r[r[i] + 1];
            tem = h[i] * (r[i] - l[i] + 1); //查找最大值
            if (ans < tem)
                ans = tem;
        }
        printf("%lld\n",ans);
    }
    return 0;
}