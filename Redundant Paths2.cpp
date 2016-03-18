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
const int MAXN = 5e3 + 111;

struct Edge {
    int to, next;
    bool cut;
}edge[MAXN];
int head[MAXN], tot, f;
int low[MAXN], dfn[MAXN], sta[MAXN], Belong[MAXN], deg[MAXN];
int index, top;
int block;
bool in[MAXN];
int bridge;

void init() {
    tot = top = index = block = 0;
    for (int i = 1; i <= f; ++i) {
        head[i] = -1;
        low[i] = dfn[i] = in[i] = deg[i] = 0;
    }
}

void add_edge(int u, int v) {
    edge[tot].to = v;
    edge[tot].cut = 0;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void tarjan(int u, int p) {
    int v;
    low[u] = dfn[u] = ++index;
    sta[top++] = u;
    in[u] = 1;

    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (v == p) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                ++bridge;
                edge[i].cut = edge[i ^ 1].cut = 1;
            }
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++block;
        do {
            v = sta[--top];
            in[v] = 0;
            Belong[v] = block;
        }while (v != u);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int r, u, v;
    scanf("%d%d", &f, &r);
    init();
    while (r --) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    tarjan(1, 0);

    for (int i = 1; i <= f; ++i) {
        for (int j = head[i]; ~j; j = edge[j].next) {
            if (edge[j].cut) ++deg[Belong[i]];
        }
    }

    int ans = 0;
    for (int i = 1; i <= block; ++i) if (deg[i] == 1) ++ans;

    printf("%d\n", (ans + 1) / 2);
    return 0;
}
