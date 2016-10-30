#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int c[MAXN];
bool vis[MAXN];
int ans = 0, mx = 0;
map<int, int> mp;
vector<int> G[MAXN];

int dfs(int u) {
    int ret = 1;
    mx = max(mx, ++mp[c[u]]);
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v]) continue;
        vis[v] = 1;
        ret += dfs(v);
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    int l, r, last = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r);
        G[l].push_back(r);
        G[r].push_back(l);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            mp.clear();
            mx = 0;
            vis[i] = 1;
            ans += dfs(i) - mx;
        }
    }
    printf("%d\n", ans);
    return 0;
}
