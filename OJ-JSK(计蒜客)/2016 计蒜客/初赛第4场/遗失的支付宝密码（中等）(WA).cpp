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

unsigned int dp[50];

int main()
{
    unsigned int n, m, ans = 0;
    cin >> n >> m;
    dp[1] = m;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] * m;
        if (i % 2 == 0) {
            int t = i / 2;
            int mul = -1;
            do {
                dp[i] += mul * dp[t];
                mul *= -1;
                t >>= 1;
            } while (t > 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
    }
    cout << ans << '\n';
    return 0;
}
