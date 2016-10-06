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
const int MAXN = 1e5 + 111;
const int MOD = 1000000007;

struct Edge {
    int to, next;
}edge[MAXN << 2];
int head[MAXN], tol;
int dfn[MAXN], low[MAXN], indx, scc, id[MAXN], top, sta[MAXN];
bool in[MAXN];
ll val[MAXN];
ll way[MAXN], aval[MAXN];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        ll mi = INF;
        ll num = 0;
        do {
            v = sta[--top];
            in[v] = 0;
            if (val[v] < mi) {
                mi = val[v];
                num = 1;
            }
            else if (val[v] == mi) {
                ++num;
            }
        } while (u != v);
        aval[scc] = mi;
        way[scc] = num;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &val[i]);
            head[i] = -1;
            dfn[i] = 0;
            in[i] = 0;
        }
        indx = tol = top = scc = 0;
        scanf("%d", &m);
        while (m --) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        ll ans1 = 0, ans2 = 1;
        for (int i = 1; i <= scc; ++i) {
            ans1 += aval[i];
            ans2 = (ans2 * way[i]) % MOD;
        }
        printf("%I64d %I64d\n", ans1, ans2);
    }
    return 0;
}
