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
const int MAXN = 1e3 + 111;

vector<int> G[MAXN];
bool mp[MAXN][MAXN];
int n, m;
int dfn[MAXN], low[MAXN], bccno[MAXN], indx, block, top, sta[MAXN];
bool in[MAXN], vis[MAXN], can[MAXN];
int temp[MAXN], cnt, color[MAXN];

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!vis[v]) continue;
        if (color[v] == -1 && !dfs(v, !c)) return 0;
        else if (color[v] != -1) {
            if (color[v] == c) return 0;
        }
    }
    return 1;
}

void tarjan(int u, int p) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;

    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == p) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                ++block;
                int sv;
                cnt = 0;
                memset(vis, 0, sizeof vis);
                do {
                    sv = sta[--top];
                    bccno[sv] = block;
                    in[sv] = 0;
                    vis[sv] = 1;
                    temp[cnt++] = sv;
                }while (sv != v);
                vis[u] = 1;

                memset(color, -1, sizeof color);
                if (!dfs(u, 0)) {
                    can[u] = 1;
                    while (cnt--)
                        can[temp[cnt]] = 1;
                }
            }
        }
        else if (in[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
}

void find_bcc() {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(in, 0, sizeof in);
    memset(bccno, 0, sizeof bccno);
    memset(can, 0, sizeof can);
    indx = block = top = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && (n|m)) {
        int u, v;
        memset(mp, 0, sizeof mp);
        for (int i = 1; i <= n; ++i) G[i].clear();
        while (m --) {
            scanf("%d%d", &u, &v);
            mp[u][v] = mp[v][u] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!mp[i][j]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        find_bcc();

        int ans = n;
        for (int i = 1; i <= n; ++i) {
            if (can[i]) --ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
