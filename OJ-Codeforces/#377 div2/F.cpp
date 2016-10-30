#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 4e5 + 111;

int n, m, mx, rt;
struct Edge {
    int u, v, nxt;
    bool choose;
}edge[MAXN << 1];
int tol, head[MAXN];
bool in[MAXN];
int dfn[MAXN], low[MAXN], indx, sta[MAXN], top;

inline void addedge(int u, int v) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].nxt = head[u];
    edge[tol].choose = false;
    head[u] = tol++;
}

void tarjan(int u, int fa) {
    sta[top++] = u;
    in[u] = 1;
    dfn[u] = low[u] = ++indx;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v = 0, sum = 0;
        do {
            v = sta[--top];
            in[v] = 0;
            ++sum;
        }while (v != u);
        if (sum > mx) {
            mx = sum;
            rt = u;
        }
    }
}

void dfs(int u, int fa) {
    dfn[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if (v == fa) continue;
        //printf("%d %d\n", u, v);
        if (dfn[v]) {
            edge[i ^ 1].choose = true;
            edge[i].choose = false;
            dfs(v, u);
        }
        else {
            edge[i].choose = true;
            edge[i ^ 1].choose = false;
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    tarjan(1, 0);
    dfs(rt, 0);
    printf("%d\n", mx);
    m <<= 1;
    for (int i = 0; i < m; ++i) {
        if (edge[i].choose) {
            printf("%d %d\n", edge[i].u, edge[i].v);
        }
    }
    return 0;
}
