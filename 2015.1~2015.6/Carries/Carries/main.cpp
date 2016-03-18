#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 1e5 + 111;
int a[MAXN];
int b[MAXN];

int main() {
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        int k = 1;
        ll ans = 0;
        for (int i = 1; i <= 9; ++i)
        {
            k *= 10;
            for (int i = 0; i < n; ++i)
                b[i] = a[i] % k;
            sort(b, b + n);
            for (int i = 0; i < n; ++i)
            {
                int l = i + 1, r = n;
                while (l < r) //如果找到了某个值可以进位，那么b[i]和它之后的肯定也能进位
                {
                    int mid = (l + r) / 2;
                    if (b[mid] + b[i] >= k)
                        r = mid;
                    else l = mid + 1;
                }
                ans += n - l;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
