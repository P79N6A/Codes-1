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
const int MAXN = 1e3 + 111;

int val[MAXN];
int cost[MAXN];
int id[MAXN];
vector<int> G[MAXN];

bool cmp(int a, int b) {
    return val[a] > val[b];
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> val[i], id[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        cost[u] += val[v];
        G[v].push_back(u);
        cost[v] += val[u];
    }

    sort(id + 1, id + 1 + n, cmp);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = id[i];
        ans += cost[cur];
        for (int j = 0; j < G[cur].size(); ++j) {
            cost[G[cur][j]] -= val[cur];
        }
    }
    cout << ans << '\n';
    return 0;
}
