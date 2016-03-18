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
const int MAXN = 4e3 + 111;

int dp[MAXN], num[4];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 3; ++i) cin >> num[i];

    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = num[i]; j <= n; ++j) {
            dp[j] = max(dp[j], dp[j - num[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
