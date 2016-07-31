#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 111;
const int maxm = 1e6 + 111;

struct Edge {
    int u, v, next;
    ll w;
    bool operator < (const Edge&t)const {
        return w < t.w;
    }
}edge[maxn * 2], edge2[maxm];
int head[maxn], tol;
int p[maxn];
ll sz[maxn];
int x[maxn], y[maxn], cnt;
ll z[maxn];

inline void init(int n) {
    tol = 0;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
        p[i] = i;
    }
}

inline void addedge(int u, int v, ll w) {
    edge[tol].v = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

ll dfs(int u, int p) {
    sz[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == p) continue;
//        printf("%d\n", v);
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, m; scanf("%d", &t);
    ll n;
    while (t --) {
        scanf("%lld%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%lld", &edge2[i].u, &edge2[i].v, &edge2[i].w);
            //printf("%d %d %lld\n", edge2[i].u, edge2[i].v, edge2[i].w);
        }
        sort(edge2, edge2 + m);
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            int u = edge2[i].u, v = edge2[i].v;
            ll w = edge2[i].w;
            int pu = find(u), pv = find(v);
            if (pu == pv) continue;
            p[pu] = pv;
            ans += w;
            addedge(u, v, w);
            addedge(v, u, w);
            x[cnt] = u, y[cnt] = v, z[cnt++] = w;
        }
//        printf("%lld\n", ans);
        dfs(1, 1);
//        for (int i = 1; i <= n; ++i) printf("%lld\n", sz[i]);
        double sum = 0;
        for (int i = 0; i < cnt; ++i) {
            int u = x[i], v = y[i];
            ll w = z[i];
            ll mi = min(sz[u], sz[v]);
            sum += w * (mi * (n * 1.0 - mi));
        }
//        printf("%.2f\n", sum);
        if (n <= 1) printf("0 0.00\n");
        else printf("%lld %.2f\n", ans, 2 * sum / (n * 1.0 * (n - 1)));
    }
    return 0;
}
