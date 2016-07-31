/*
  首先dfs一遍，将所有连通块的值求出。存储在sum中
  对于非割点u，答案就是sum - comp[x] + comp[x] * pow(u, MOD - 2)
  其中x是点u所属的连通块编号，comp是连通块值
  对于割点u，在tarjan的时候求出。用mul记录割点的所有子树的乘积，
  sub记录割点的所有子树的和，对于处于父亲的块的和，使用comp和mul
  进行求解。
 */
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
const int MOD = 1e9 + 7;

vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], indx;
bool in[MAXN], vis[MAXN], cut[MAXN];
ll w[MAXN];
int cnt;
int belong[MAXN];
ll comp[MAXN], dp[MAXN], ans, sum;
ll mul[MAXN], sub[MAXN];

ll quickPow(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % MOD;
        p >>= 1;
        base = base * base % MOD;
    }
    return ret;
}

inline void init(int n) {
    indx = 0;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        dfn[i] = 0;
        vis[i] = 0;
        cut[i] = 0;
        mul[i] = 1;
        sub[i] = 0;
        G[i].clear();
    }
}

void dfs(int u, int number) {
    vis[u] = 1;
    dp[u] = w[u];
    belong[u] = number;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v]) continue;
        dfs(v, number);
        dp[u] = (dp[u] * dp[v]) % MOD;
    }
    return;
}

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cut[u] = 1;
                sub[u] = (sub[u] + dp[v]) % MOD;
                mul[u] = (mul[u] * dp[v]) % MOD;
            }
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (cut[u]) {
        mul[u] = mul[u] * w[u] % MOD;
        int x = belong[u];
        ll z = (sum - comp[x] + MOD) % MOD;
        z = (z + sub[u] + comp[x] * quickPow(mul[u], MOD - 2) - (u == f)) % MOD;
        ans = (ans + u * z) % MOD;
    }
    in[u] = 0;
    return;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int n, m, u, v; scanf("%d%d", &n, &m);
        init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &w[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ++cnt;
                dfs(i, cnt);
                comp[cnt] = dp[i];
                sum = (sum + dp[i]) % MOD;
            }
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i, i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) continue;
            ll z;
            if (G[i].size() == 0) {
                z = (sum - w[i] + MOD) % MOD;
            }
            else {
                int x = belong[i];
                z = sum - comp[x];
                z = (z + comp[x] * quickPow(w[i], MOD - 2)) % MOD;
            }
            ans = (ans + i * z) % MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
    }
    return 0;
}
