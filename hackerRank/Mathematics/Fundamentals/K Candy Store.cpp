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
const int MAXN = 1e3 + 111;
const int MOD = 1e9;

int dp[MAXN][MAXN];

inline void init() {
	for (int i = 1; i <= 1000; ++i) dp[1][i] = i;
	for (int i = 2; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t, n, k;
    cin >> t;
    init();
    while (t --) {
    	cin >> n >> k;
    	cout << dp[k][n] << '\n';
    }
    return 0;
}