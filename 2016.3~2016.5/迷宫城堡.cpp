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
const int MAXN = 1e4 + 111;

struct Edge {
    int to, next;
}edge[1001000];
int head[MAXN], sta[MAXN], dfn[MAXN], low[MAXN], top, indx, tol;
bool in[MAXN];
int n, m;

void init() {
    top = indx = tol = 0;
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(in, 0, sizeof in);
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

bool tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (u == 1 && top == n) return 1;
    if (dfn[u] == low[u]) {
        do {
            v = sta[--top];
            in[v] = 0;
        } while (v != u);
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v;
    while (~scanf("%d%d", &n, &m) && (m|n)) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        if (tarjan(1)) {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
