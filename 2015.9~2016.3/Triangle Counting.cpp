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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 11;

ll dp[MAXN];

void init()
{
    dp[3] = 0;
    for (ll i = 4; i < MAXN; ++i)
    {
        if (i % 2)
            dp[i] = dp[i - 1] + ((i - 3) / 2)* ((i - 3) / 2 + 1);
        else dp[i] = dp[i - 1] + ((i - 2) / 2) * ((i - 3) / 2 + 1);
    }
}

int main()
{
    init();
    int n;
    while (cin >> n && n >= 3)
    {
        cout << dp[n] << '\n';
    }
    return 0;
}
