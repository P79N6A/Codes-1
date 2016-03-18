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

bool is(ll n)
{
    if (n == 1) return 0;
    ll up = sqrt(n);
    for (ll i = 2; i <= up; ++i)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll b, n;
    while (cin >> b >> n)
    {
        ll num = 0, base = 1;
        for (int i = 0; i < n; ++i)
        {
            num += base;
            base *= b;
        }
        if (is(num)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

