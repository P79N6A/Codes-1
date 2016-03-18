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

int dp[MAXN];
int s[5] = {1, 2, 3, 4, 5};
int main()
{
    memset(dp, 0x7f, sizeof dp);
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = s[i]; j <= n; ++j) {
            dp[j] = min(dp[j], dp[j - s[i]] + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
