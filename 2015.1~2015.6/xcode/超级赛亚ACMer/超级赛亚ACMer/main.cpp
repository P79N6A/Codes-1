#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 111;
typedef long long ll;

ll a[MAXN];

int main() {
    int t; scanf("%d", &t);
    int cnt = 0;
    while (t --)
    {
        ll n, m, k;
        scanf("%I64D %I64D %I64D", &n, &m, &k);
        for (int i = 0; i < n; ++i)
            scanf("%I64D", &a[i]);
        sort(a, a + n);
        int q = upper_bound(a, a + n, m) - a;
        if (q == 0)
        {
            printf("Case #%d:\n", ++cnt);
            printf("madan!\n");
            continue;
        }
        ll energy = a[q - 1];
        bool flag = 0;
        for (int i = q; i < n; ++i)
        {
            if (energy + k >= a[i])
            {
                energy = a[i];
                --k;
            }
            else {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf("Case #%d:\n", ++cnt);
            printf("madan!\n");
        }
        else {
            printf("Case #%d:\n", ++cnt);
            printf("why am I so diao?\n");
        }
    }
    
    return 0;
}