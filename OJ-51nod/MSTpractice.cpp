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
const int MAXN = 5e4 + 111;

struct Edge {
    int u, v, w;
    bool operator < (const Edge & t) const {
        return w < t.w;
    }
}edge[MAXN];
int par[MAXN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge, edge + m);
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int u = find(edge[i].u), v = find(edge[i].v);
        if (u != v) {
            par[u] = v;
            ans += edge[i].w;
        }
    }
    cout << ans << '\n';
    return 0;
}
