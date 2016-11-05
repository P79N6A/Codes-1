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
const int MAXN = 1e5 + 111;
const int MOD = 1e9 + 7;

// dp:深度i不同构的二叉树个数
// sum:深度不超过i不同够的二叉树总数
ll dp[MAXN], sum[MAXN];

ll quick_pow(ll base, ll p) {
	ll ret = 1;
	for (; p; base = base * base % MOD, p >>= 1) {
		if (p & 1) {
			ret = ret * base % MOD;
		}
	}
	return ret;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int k;
    dp[0] = 1;
    sum[0] = 1;
    dp[1] = 1;
    sum[1] = 2;
    ll inv2 = quick_pow(2, MOD - 2);
    ll inv6 = quick_pow(6, MOD - 2);
    for (int i = 2; i <= 100000; ++i) {
        // dp[i]分两种情况：
        // 1.一个分支为i - 1，另一个小于i - 1
        // 2.两个分支都为i - 1
        dp[i] = ((dp[i - 1] + (dp[i - 1] * (dp[i - 1] - 1) % MOD * inv2) % MOD)
              + dp[i - 1] * sum[i - 2]) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    while (~scanf("%d", &k) && k) {
        int cur = k / 2;
        ll ans = 0;
        if (k % 2 == 0) {
            // 两边一样，分相同和不同两种情况
            ans = (dp[cur] + (dp[cur] * (dp[cur] - 1) % MOD * inv2)) % MOD;
        }
        else {
            // 第三边小于cur
            ans = (dp[cur] + (dp[cur] * (dp[cur] - 1) % MOD * inv2 % MOD)) * sum[cur - 1] % MOD;
            // 三边长度相同时，三种情况：
            // 两边相同
            ans = (ans + dp[cur] * (dp[cur] - 1) % MOD) % MOD;
            // 三边相同
            ans = (ans + dp[cur]) % MOD;
            // 三边不同
            ans = (ans + dp[cur] * (dp[cur] - 1) % MOD * (dp[cur] - 2) % MOD * inv6 % MOD) % MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
    }
    return 0;
}