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
const int MAXN = 511;

ll mp[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll ans[MAXN];
bool in[MAXN];
int x[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
            dp[i][j] = mp[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = n; i >= 1; --i) {
        int u = x[i];
        in[u] = 1;
        for (int v = 1; v <= n; ++v) {
            for (int j = 1; j <= n; ++j) {
                dp[v][j] = min(dp[v][j], dp[v][u] + dp[u][j]);
            }
        }
        ll sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (in[j]) {
                for (int k = 1; k <= n; ++k) {
                    if (in[k]) {
                        sum += dp[j][k];
                    }
                }
            }
        }
        ans[i] = sum;
    }
    cout << ans[1];
    for (int i = 2; i <= n; ++i) cout << ' ' << ans[i];
    return 0;
}
