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
const int MAXN = 1e4 + 111;

int a[MAXN], b[MAXN], c[MAXN];
int n, m;
vector<int> G[500];
int dfn[500], low[500], sta[500], in[500], id[500], top, scc, indx;

void init() {
    top = scc = indx = 0;
    for (int i = 0; i < 2 * n; ++i) {
        G[i].clear();
        dfn[i] = in[i] = 0;
    }
}

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = 0; i < G[u].size(); ++i) {
        v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        ++scc;
        do {
            v = sta[--top];
            in[v] = 0;
            id[v] = scc;
        } while (v != u);
    }
}

bool ok(int up) {
    for (int i = 0; i < up; ++i) {
        if (c[i] == 0) {
            G[a[i]].push_back(b[i]);
            G[b[i]].push_back(a[i]);
        }
        else if (c[i] == 1) {
            G[a[i]].push_back(b[i] + n);
            G[b[i] + n].push_back(a[i]);
            G[b[i]].push_back(a[i] + n);
            G[a[i] + n].push_back(b[i]);
        }
        else {
            G[a[i] + n].push_back(b[i] + n);
            G[b[i] + n].push_back(a[i] + n);
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 0; i < n; ++i) {
        if (id[i] == id[i + n]) return 0;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            init();
            if (ok(mid)) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
