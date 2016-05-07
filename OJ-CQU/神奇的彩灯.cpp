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
const int MAXM = 1e6 + 111;

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int e[MAXN], head[MAXN], tol, dfn[MAXN], low[MAXN], indx, top, block;
int nxt[MAXM], to[MAXM];

void addedge(int u, int v) {
    to[tol] = v;
    nxt[tol] = head[u];
    head[u] = tol++;
}

bool Instack[MAXN];
int Stack[MAXM], Belong[MAXN];
void Tarjan(int u) {
    int v;
    low[u] = dfn[u] = ++indx;
    Stack[top++] = u;
    Instack[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        v = to[i];
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
    indx = top = block = 0;
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i);

    memset(e,0,sizeof(e));
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; ~j; j = nxt[j]) {
            int v = to[j];
            if (Belong[i] != Belong[v]) ++e[Belong[v]];
        }
    }
}


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, kase = 0, u, v;
    memset(Instack, 0,sizeof(Instack));
    while (scanf("%d%d", &n, &m) == 2) {
        memset(head, -1, sizeof head);
        tol = 0;
        while (m --) {
            u = read(), v = read();
            addedge(u, v);
        }

        solve(n);

        int ans = 0;
        for (int i = 1; i <= block; ++i) {
            if (e[i] == 0) ++ans;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
