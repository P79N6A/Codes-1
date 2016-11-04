#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e6 + 111;
const int MOD = 1e9 + 7;

ll f[MAXN];

inline void init() {
	f[0] = 1;
	for (int i = 1; i <= 2e6; ++i) {
		f[i] = f[i - 1] * i % MOD;
	}
}

ll quick_pow(ll base, ll p) {
	ll ret = 1;
	for (; p; base = base * base % MOD, p >>= 1) {
		if (p & 1) {
			ret = ret * base % MOD;
		}
	}
	return ret;
}

int C(int n, int m) {
	ll up = 1;
	for (int i = m - n + 1; i <= m; ++i) up = up * i % MOD;
	return up * quick_pow(f[n], MOD - 2) % MOD;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t, n, m; scanf("%d", &t);
    init();
    while (t --) {
    	scanf("%d%d", &n, &m);
    	--n, --m;
    	printf("%d\n", C(n, m + n));
    }
    return 0;
}