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
const int MAXN = 1e5 + 111;

vector<int> G[MAXN];
int vis[MAXN];

int n, m;
ll ans = 0;

void dfs(int u, ll len) {
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v > u && len + 1 > vis[v]) {
            dfs(v, len + 1);
        }
    }
    ans = max(ans, len * G[u].size());
}

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
