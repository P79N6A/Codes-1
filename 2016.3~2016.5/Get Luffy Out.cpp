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
const int MAXN = 6e3 + 111;

int u[MAXN], v[MAXN], n, m;
vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], scc[MAXN], indx, scc_num, top;
bool in[MAXN];
int key1[MAXN], key2[MAXN];

void build(int up) {
    indx = scc_num = top = 0;
    for (int i = 0; i < 4 * n; ++i) {
        G[i].clear();
        in[i] = dfn[i] = 0;
    }
    for (int i = 1; i <= up; ++i) {
        int x = u[i], y = v[i];
        G[y + 2 * n].push_back(x);
        G[x + 2 * n].push_back(y);
    }
    for (int i = 0; i < n; ++i) {
        G[key1[i]].push_back(key2[i] + 2 * n);
        G[key2[i]].push_back(key1[i] + 2 * n);
    }
}

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    sta[top++] = u;
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
        ++scc_num;
        do {
            v = sta[--top];
            in[v] = 0;
            scc[v] = scc_num;
        } while (v != u);
    }
}

bool ok() {
    for (int i = 0; i < 4 * n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (scc[i] == scc[i + 2 * n]) return 0;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && (n | m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &key1[i], &key2[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
        }

        int l = 1, r = m, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            build(mid);
            if (ok()) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
