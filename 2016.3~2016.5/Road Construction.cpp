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
const int MAXN = 1111;

vector<int> G[MAXN];
int dfn[MAXN], e[MAXN], low[MAXN], sta[MAXN], belong[MAXN];
int top, indx, sccno, n;
bool in[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        dfn[i] = 0;
        in[i] = 0;
        e[i] = 0;
    }
    indx = sccno = top = 0;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = 0; i < G[u].size(); ++i) {
        v = G[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++sccno;
        do {
            v = sta[--top];
            belong[v] = sccno;
            in[v] = 0;
        }while (v != u);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, u, v;
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        tarjan(1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < G[i].size(); ++j) {
                u = belong[i], v = belong[G[i][j]];
                if (u == v) continue;
                ++e[v];
            }
        }

        int ans = 0;
        for (int i = 1; i <= sccno; ++i) {
            if (e[i] == 1) ++ans;
        }
        printf("%d\n", (ans + 1) / 2);
    }
    return 0;
}
