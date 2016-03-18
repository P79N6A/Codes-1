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
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

ll mod;

ll quickpow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret = (ret%mod * a%mod)%mod;
        }
        b >>= 1;
        a = (a%mod * a % mod) %mod;
    }
    return ret % mod;
}

int main()
{
    ll a;
    while (~scanf("%lld %lld", &a, &mod))
    {
        mod *= 9;
        printf("%lld\n", (quickpow(10, a) - 1) / 9);
    }
    return 0;
}
