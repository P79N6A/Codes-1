#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pll pair<ll, ll>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int mod = 110119;

ll fac[mod];
ll inv[mod];
ll facinv[mod];

void init()
{
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for(int i = 2; i < mod; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll C(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n)
		return 0;
	return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

ll Lucas(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n)
		return 0;
	ll res = 1;
	while(n || m) {
		res = res * C(n % mod, m % mod) % mod;
		n /= mod;
		m /= mod;
	}
	return res;
}

ll Solve(ll n, ll m) { return Lucas(n + m, n); }

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    ll n, m, x, y;
    int r, kase = 0;
    while (~scanf("%lld%lld%d", &n, &m, &r)) {
        vector<pll> bad;
        while (r --) {
            scanf("%lld%lld", &x, &y);
            bad.push_back(make_pair(x, y));
        }
        bad.push_back(make_pair(1, 1));
        bad.push_back(make_pair(n, m));
        sort(bad.begin(), bad.end());
        vector<ll> dp(bad.size(), 0);
        // 这样设定在j = 0的时候将dp[i]初始化
        dp[0] = mod - 1;
        for (int i = 0; i < bad.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                ll x1 = bad[i].first, y1 = bad[i].second;
                ll x2 = bad[j].first, y2 = bad[j].second;
                if (x1 < x2 || y1 < y2 || (x1 + y1 - x2 - y2) % 3) continue;
                ll del = (x1 + y1 - x2 - y2) / 3;
                dp[i] = (dp[i] + mod - dp[j] * Solve(x1 - x2 - del, y1 - y2 - del) % mod) % mod;
            }
        }
        printf("Case #%d: %lld\n", ++kase, dp.back());
    }
    return 0;
}
