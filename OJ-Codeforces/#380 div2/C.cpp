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
const int MAXN = 2e5 + 111;

ll c[MAXN], v[MAXN], g[MAXN];
vector<ll> len, sum;
int n, k, s, t, ans = -1, cost = 2e9;

bool ok(int x) {
	ll tank = v[x];
	ll half = tank / 2;
	if (tank < len.back()) return 0;
	int pos = upper_bound(len.begin(), len.end(), half) - len.begin() - 1;
	ll tol = sum[pos];
	ll lef = len.size() - pos - 1;
	ll temp = sum[len.size() - 1] - sum[pos];
	tol += 2 * temp - (lef * tank - temp);
	return tol <= t;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 1; i <= n; ++i) {
    	scanf("%lld%lld", &c[i], &v[i]);
    }
    for (int i = 1; i <= k; ++i) {
    	scanf("%lld", &g[i]);
    }
    sort(g + 1, g + 1 + k);
    g[k + 1] = s;
    for (int i = 1; i <= k + 1; ++i) {
    	len.push_back(g[i] - g[i - 1]);
    }
    sort(len.begin(), len.end());
    for (int i = 0; i < len.size(); ++i) {
    	sum.push_back(len[i]);
    	if (i) {
    		sum[i] += sum[i - 1];
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	if (ok(i) && cost > c[i]) {
    		cost = c[i];
    		ans = i;
    	}
    }
    if (ans != -1)
    	printf("%d\n", cost);
    else printf("%d\n", ans);
    return 0;
}