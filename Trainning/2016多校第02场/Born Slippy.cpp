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

const int MAXN = (1 << 16) + 10;
const int N = (1 << 8) + 5;
const int MOD = 1e9 + 7;

char op[4];
vector<int> G[MAXN];
ll ans;
ll w[MAXN];
ll dp[N][N]; // dp[X][Y]: w[i]前八位为X，w[j]后八位为Y，w[i]的后八位操作w[j]的后八位的最大值。i < j
ll bk[MAXN][N];

ll cal(ll a, ll b) {
    switch(op[0]) {
        case 'A': return a & b;
        case 'X': return a ^ b;
        case 'O': return a | b;
    }
}

void dfs(int u) {
    ll val = 0;
    ll a = w[u] >> 8, b = w[u] & 255;
    for (int i = 0; i < 256; ++i) {
        if (dp[i][b] != -1)
            val = max(val, dp[i][b] + (cal(a, i) << 8));
    }
    ans = (ans + u * (val + w[u])) % MOD;
    copy(dp[a], dp[a] + 256, bk[u]);
    for (int i = 0; i < 256; ++i) {
        dp[a][i] = max(dp[a][i], val + cal(b, i));
    }
    for (int v : G[u]) {
        dfs(v);
    }
    copy(bk[u], bk[u] + 256, dp[a]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, x, n; scanf("%d", &t);
    while (t --) {
        scanf("%d%s", &n, op);
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            scanf("%lld", &w[i]);
        }
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &x);
            G[x].push_back(i);
        }
        memset(dp, -1, sizeof dp);
        ans = 0;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
