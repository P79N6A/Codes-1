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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
const int MOD = 1e9 + 7;

ll dp[200][2];

ll quick_pow(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = (ret * base) % MOD;
        p >>= 1;
        base = (base * base) % MOD;
    }
    return ret;
}

int main()
{
    int n; cin >> n;
    dp[1][0] = dp[1][1] = 1;;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (j == 1 && k == 1) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int sum = (dp[n][0] + dp[n][1]) % MOD;
    cout << (quick_pow(2, n) - sum + MOD) % MOD << endl;
    return 0;
}
