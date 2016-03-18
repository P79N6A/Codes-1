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

int dp[MAXN], b[MAXN];

int main()
{
    int n, up = 0; cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        cin >> b[x];
        up = max(up, x);
    }
    int ans = 0;
    for (int i = 0; i <= up; ++i) {
        if (b[i] == 0) {
            if (i > 0)
                dp[i] = dp[i - 1];
        }
        else if (b[i] >= i) dp[i] = 1;
        else dp[i] = dp[i - b[i] - 1] + 1;
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
    return 0;
}
