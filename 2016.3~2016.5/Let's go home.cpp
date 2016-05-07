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

vector<int> G[MAXN];
int n, m;
int dfn[MAXN], low[MAXN], sta[MAXN], id[MAXN], indx, scc, top;
bool in[MAXN];

void init() {
    for (int i = 0; i <= 6 * n; ++i) {
        G[i].clear();
        in[i] = 0;
        dfn[i] = 0;
    }
    indx = scc = top = 0;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        ++scc;
        int v;
        do {
            v = sta[--top];
            in[v] = 0;
            id[v] = scc;
        } while (v != u);
    }
}

int main()
{
    int a, b, c;
    while (~scanf("%d%d", &n, &m)) {
        init();
        int add = 3 * n;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            G[a + add].push_back(c);
            G[a + add].push_back(b);
            G[b + add].push_back(a);
            G[c + add].push_back(a);
        }
        int u, v;
        while (m --) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v + add);
            G[v].push_back(u + add);
        }

        for (int i = 0; i < 6 * n; ++i) {
            if (!dfn[i]) tarjan(i);
        }

        bool flag = 1;
        for (int i = 0; i < 3 * n; ++i) {
            if (id[i] == id[i + 3 * n]) {
                flag = 0;
                break;
            }
        }
        printf("%s\n", flag? "yes" : "no");
    }
    return 0;
}
