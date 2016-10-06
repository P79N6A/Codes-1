#include<iostream>
#include<cctype>
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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4 + 111;
ll dp[MAXN], n, three[MAXN];

void init()
{
    for (int i = 3; i <= 10000; ++i)
    {
        three[i] = 18446744073709551615;
        dp[i] = 18446744073709551615;
    }
    three[0] = 0, three[1] = 1;
    for (int i = 2; i <= 64; ++i) three[i] = 2 * three[i - 1] + 1;
    //pr(three[64]);
    dp[0] = 0, dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= 10000; ++i)
        for (int j = max(1, i - 60); j <= i; ++j)
            dp[i] = min(dp[i], 2 * dp[j] + three[i - j]);

}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    while (cin >> n)
        cout << dp[n] << '\n';
    return 0;
}

