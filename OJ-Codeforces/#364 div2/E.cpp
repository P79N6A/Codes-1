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
const int MAXN = 2e5 + 111;

bool cut[MAXN];
ll dp[MAXN];
int k;
vector<int> G[MAXN];

ll ans = 0;
void dfs(int u, int f) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u);
        dp[u] += dp[v];
        if (dp[v] > k)
            ans += k - (dp[v] - k);
        else ans += dp[v];
    }
    if (cut[u]) ++dp[u];
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x, u, v;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 2 * k; ++i) {
        scanf("%d", &x);
        cut[x] = 1;
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    printf("%I64d\n", ans);
    return 0;
}
