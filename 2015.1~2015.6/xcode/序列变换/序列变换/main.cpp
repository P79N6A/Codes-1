#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 111;

int a[MAXN], b[MAXN];

int main() {
    int t; scanf("%d", &t);
    int cnt = 0;
    while (t --)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        a[0] = b[0] = 0;
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] < a[i - 1])
            {
                int diff = ceil((a[i - 1] - a[i]) / 2.0);
                if (a[i - 1] - diff > a[i - 2])
                {
                    a[i - 1] -= diff;
                    a[i] = a[i - 1] + 1;
                    ans = max(ans, max(abs(a[i] - b[i]), abs(b[i - 1] - a[i - 1])));
                }
                else {
                    a[i - 1] = a[i - 2] + 1;
                    a[i] = a[i - 1] + 1;
                    ans = max(ans, max(abs(a[i] - b[i]), abs(b[i - 1] - a[i - 1])));
                }
            }
            else if (a[i] == a[i - 1])
            {
                if (a[i - 1] - a[i - 2] > 1)
                    --a[i - 1];
                else ++a[i];
                ans = max(ans, 1);
            }
        }
        printf("Case #%d:\n", ++cnt);
        printf("%d\n", ans);
    }
    return 0;
}
