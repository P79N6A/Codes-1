#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 2e3 + 111, MOD = 1000000007;
int n, m, k, x, y, p[MAXN];
ll dp[MAXN][2];
vector<int> G[MAXN];
map<int, bool> mp;

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

ll dfs(int u, int x)
{
    ll &ret = dp[u][mp[x]];
    if (ret >= 0) return ret;
    if (x >= k) return ret = 0;
    mp[x] = 1;
    ret = 0;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        //pr(v);
        ll temp = lcm(p[v], x);
        if (temp == k && v == n)
        {
            ++ret;
            continue;
        }
        if (temp > x)
            ret = (ret + dfs(v, temp)) % MOD;
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        mp.clear();
        memset(dp, -1, sizeof dp);
        for (int i = 0; i <= n; ++i) G[i].clear();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
        }
        for (int i = 1; i <= n; ++i) scanf("%d", p + i);
        printf("%lld\n", dfs(1, p[1]));
    }
    return 0;
}
