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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 31;

ll dp[MAXN];
void init()
{
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 5;
    for (int i = 4; i <= 20; ++i)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2] + (i - 1) * (i - 2) / 2 * dp[i - 3];
    }
}

int main()
{
    init();
    int n;
    while (cin >> n && n)
    {
        cout << dp[n] << '\n';
    }
    return 0;
}
