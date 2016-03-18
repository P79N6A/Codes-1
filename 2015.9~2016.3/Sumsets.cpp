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
const int MAXN = 1e6 + 111;
const int MOD = 1e9;

int dp[MAXN];

int main()
{
    int n;
    scanf("%d", &n);

    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (i % 2) dp[i] = dp[i - 1];
        else dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
    }
    printf("%d\n", dp[n]);
    return 0;
}
