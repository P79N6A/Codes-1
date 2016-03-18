#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
typedef unsigned long long ll;

ll C(ll n, ll m)
{
	if (n < m - n) n = m - n;
	ll ret = 1;
	ll p = 1;
	for (ll i = m; i > n; --i)
	{
		ret *= i;
		if (p <= m - n)
		{
			ret /= p;
			++p;
		}
	}
	return ret;
}

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	ll n, m, t;
	while (cin >> n >> m >> t)
	{
		ll ans = 0;
		for (ll i = 4; i <= t; ++i)
		{
			ll a = i, b = t - i;
			if (a <= n && b <= m && b >= 1)
			{
				ans += C(a,n) * C(b, m);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

