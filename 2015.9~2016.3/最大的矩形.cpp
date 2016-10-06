#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

ll h[MAXN], l[MAXN], r[MAXN];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &h[i]);
            l[i] = r[i] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            while (l[i] >= 1 && h[l[i] - 1] >= h[i]) l[i] = l[l[i] - 1];
        }
        ll ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            while (r[i] <= n - 2 && h[r[i] + 1] >= h[i]) r[i] = r[r[i] + 1];
            ll temp = h[i] * (r[i] - l[i] + 1);
            ans = max(ans, temp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
