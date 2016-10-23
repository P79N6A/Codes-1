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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e7 + 11;

ll dp[MAXN], n, x, y;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    while (cin >> n >> x >> y) {
        dp[1] = x, dp[0] = 1e15;
        for (int i = 2; i <= n; ++i) {
            int base = ceil(i / 2.0);
            dp[i] = min(dp[i - 1] + x, dp[base] + y + (base * 2 - i) * x);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}