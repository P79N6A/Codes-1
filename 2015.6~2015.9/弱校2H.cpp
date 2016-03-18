#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef unsigned long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

int main()
{
    ll m, n, ans;
    while (cin >> m >> n)
    {
        ll sum = (m + 1) * (n + 1);
        ans = sum * (sum - 1) * (sum - 2) / 6;
        ll total = 0;
        for (ll i = 1; i <= m; ++i)
            for (ll j = 1; j <= n; ++j)
            {
                ll judge = __gcd(i, j);
                if (judge != 1)
                {
                    ll node = judge - 1;
                    total += (m - i + 1) * (n - j + 1) * node;
                }
            }
        total *= 2;
        if (m + 1 >= 3)
            total += (n + 1) * (m + 1) * m * (m - 1) / 6;
        if (n + 1 >= 3)
            total += (m + 1) * (n + 1) * n * (n - 1) / 6;
        cout << ans - total << '\n';
    }
    return 0;
}

