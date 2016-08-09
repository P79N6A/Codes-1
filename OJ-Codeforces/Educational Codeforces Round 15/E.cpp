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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

ll n, k;
ll mi[MAXN][40];
ll dp[MAXN][40];
int to[MAXN][40];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; ++i) cin >> x, to[i][0] = x;
    for (int i = 0; i < n; ++i) cin >> x, dp[i][0] = x, mi[i][0] = x;
    for (int i = 1; i < 40; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[j][i] = dp[j][i - 1] + dp[to[j][i - 1]][i - 1];
            mi[j][i] = min(mi[j][i - 1], mi[to[j][i - 1]][i - 1]);
            to[j][i] = to[to[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        ll ans1 = 0, ans2 = 1e9;
        int u = i;
        ll temp = k, step = 1;
        while (temp) {
            if (temp & 1) {
                ans1 += dp[u][step - 1];
                ans2 = min(ans2, mi[u][step - 1]);
                u = to[u][step - 1];
            }
            temp >>= 1;
            ++step;
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
    return 0;
}
