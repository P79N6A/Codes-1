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
const int MAXN = 5e3 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN * 2];
int head[MAXN], dfn[MAXN], low[MAXN], indx, tol;
int cut[MAXN], del;
bool in[MAXN];

void init(int n) {
    indx = 0;
    for (int i = 0; i < n; ++i) {
        dfn[i] = in[i] = cut[i] = 0;
    }
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void tarjan(int u, int p) {
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    int v;
    int son = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        v = edge[i].to;
        if (v == p || v == del) continue;
        if (!dfn[v]) {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u != p && low[v] >= dfn[u]) {
                ++cut[u];
            }
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (u == p) cut[u] = son - 1;
    in[u] = 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        memset(head, -1, sizeof head);
        tol = 0;
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            del = i;
            int scc = 0;
            init(n);
            for (int j = 0; j < n; ++j) {
                if (j != del && !dfn[j]) {
                    ++scc;
                    tarjan(j, j);
                }
            }
            for (int j = 0; j < n; ++j) {
                if (j != del) ans = max(ans, scc + cut[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
