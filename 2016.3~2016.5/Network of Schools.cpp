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
const int MAXN = 111;
const int MAXM = 1e4 + 111;

struct Edge {
    int next, to;
}edge[MAXM];
int out[MAXN], in[MAXN], head[MAXN], tol, dfn[MAXN], low[MAXN], Index, top, block;

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

bool Instack[MAXN];
int Stack[MAXN], Belong[MAXN];
void Tarjan(int u) {
    int v;
    low[u] = dfn[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (!dfn[v]) {
            Tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if (Instack[v]) low[u] = min(dfn[v], low[u]);
    }

    if (low[u] == dfn[u]) {
        ++block;
        do {
            v = Stack[--top];
            Instack[v] = 0;
            Belong[v] = block;
        }while (v != u);
    }
}

void solve(int n) {
    memset(dfn,0,sizeof dfn);
    Index = top = block = 0;
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i);

    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; ~j; j = edge[j].next) {
            int v = edge[j].to;
            if (Belong[i] != Belong[v]) ++out[Belong[i]], ++in[Belong[v]];
        }
    }
}


int main()
{
    int n, m, kase = 0, u, v;
    memset(Instack, 0,sizeof(Instack));
    while (~scanf("%d", &n)) {
        memset(head, -1, sizeof head);
        tol = 0;
        for (int i = 1; i <= n; ++i) {
            while (scanf("%d", &v) && v) {
                addedge(i, v);
            }
        }

        solve(n);

        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= block; ++i) {
            if (in[i] == 0) ++ans1;
            if (out[i] == 0) ++ans2;
        }
        int ans = max(ans1, ans2);
        if (block == 1)
            ans = 0;
        printf("%d\n%d\n", ans1, ans);
    }
    return 0;
}
