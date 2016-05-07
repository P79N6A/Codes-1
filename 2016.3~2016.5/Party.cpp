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
const int MAXN = 2e3 + 111;

vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], top, cnt, id[MAXN], scc;
bool in[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
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
            id[v] = scc;
            in[v] = 0;
        }while (v != u);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, a, b, c, d;
    while (~scanf("%d%d", &n, &m)) {
        top = cnt = scc = 0;
        for (int i = 0; i <= 2 * n; ++i) {
            G[i].clear();
            in[i] = 0;
            dfn[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            a *= 2; b *= 2;
            a += c; b += d;
            G[b].push_back(a ^ 1);
            G[a].push_back(b ^ 1);
        }

        for (int i = 0; i < 2 * n; ++i) {
            if (!dfn[i])
                tarjan(i);
        }

        bool flag = 1;
        for (int i = 0; i < 2 * n; i += 2) {
            if (id[i] == id[i + 1]) {
                flag = 0;
                break;
            }
        }
        printf("%s\n", flag? "YES" : "NO");
    }
    return 0;
}
