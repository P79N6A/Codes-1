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
const int MAXN = 1e5 + 111;
const int mod = 1e9 + 7;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int head[MAXN], tol;

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

int dfn[MAXN], low[MAXN], id[MAXN], sta[MAXN], scc, tp, indx;
int val[MAXN];
bool in[MAXN];

inline void init(int n) {
    tol = scc = tp = indx = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
        dfn[i] = 0;
    }
}

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    sta[tp++] = u;
    int v;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        v = edge[i].to;
        if (v == f) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int cnt = 0, vn;
        do {
            v = sta[--tp];
            in[v] = 0;
            id[v] = scc;
            ++cnt;
        } while(v != u);
        if (cnt > 1) val[scc] = 1;
        else val[scc] = 0;
    }
}

// 它们分别是：深度，重儿子，儿子数，链顶端，父亲节点，在数组中位置，位置代表的节点
int dep[MAXN], son[MAXN], num[MAXN], top[MAXN], fa[MAXN], p[MAXN], fp[MAXN];
int w[MAXN];
int pos;

void dfs1(int u, int pre, int d) {
    dep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != pre) {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[son[u]] < num[v]) {
                son[u] = v;
            }
        }
    }
}

void dfs2(int u, int f) {
    p[u] = ++pos;
    top[u] = f;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    dfs2(son[u], f);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

int x[MAXN], y[MAXN];

void add(int x, int val) {
    for (int i = x; i <= pos; i += i & -i) {
        w[i] += val;
    }
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ret += w[i];
    }
    return ret;
}

int query(int u, int v) {
    int ret = 0, fu = top[u], fv = top[v];
    //printf("%d %d\n", u, v);
    while (fu != fv) {
        if (dep[fu] < dep[fv]) swap(fu, fv), swap(u, v);
        ret += sum(p[u]) - sum(p[fu] - 1);
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return ret + sum(p[v]) - sum(p[u] - 1);
}

ll quickPow(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        p /= 2;
        base = base * base % mod;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, q, u, v;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        x[i] = u, y[i] = v;
        addedge(u, v);
        addedge(v, u);
    }
    tarjan(1, 1);
//    for (int i = 1; i <= n; ++i) {
//        printf("%d %d\n", i, id[i]);
//    }
    memset(head, -1, sizeof head);
    tol = 0;
    for (int i = 0; i < m; ++i) {
        x[i] = id[x[i]], y[i] = id[y[i]];
        if (x[i] == y[i]) continue;
        addedge(x[i], y[i]);
        addedge(y[i], x[i]);
    }
    memset(son, -1, sizeof son);
    dfs1(1, 0, 0);
    dfs2(1, 1);
    for (int i = 1; i <= scc; ++i) {
        add(p[i], val[i]);
    }
//    for (int i = 1; i <= scc; ++i) prln(sum(i))
//    for (int i = 1; i <= scc; ++i) {
//        printf("%d %d\n", i, top[i]);
//    }
    scanf("%d", &q);
    while (q --) {
        scanf("%d%d", &u, &v);
        //printf("%d %d\n", id[u], id[v]);
        ll ans = quickPow(2LL, query(id[u], id[v]));
        printf("%I64d\n", ans);
    }
    return 0;
}
