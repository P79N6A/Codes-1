/*
 * 求删除每个割点之后剩余的连通分量个数
 */
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
const int MAXN = 1111;

vector<int> G[MAXN];
int low[MAXN], dfn[MAXN], in[MAXN], indx;
int num[MAXN]; // 连通分量个数

void init() {
    for (int i = 0; i < MAXN; ++i) {
        G[i].clear();
        in[i] = num[i] = 0;
        dfn[i] = 1;
    }
    indx = 0;
}

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++indx;
    int child = 0;
    in[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f) continue;
        if (!dfn[v]) {
            ++child;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u != f && dfn[u] <= low[v]) {
                ++num[u];
            }
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (u == f) num[u] = max(0, child - 1);
    in[u] = 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v, kase = 0;
    while (scanf("%d", &u) && u) {
        init();
        scanf("%d", &v);
        G[u].push_back(v);
        G[v].push_back(u);
        dfn[u] = dfn[v] = 0;
        while (scanf("%d", &u) && u) {
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
            dfn[u] = dfn[v] = 0;
        }
        int cnt = 0; // 原图连通分量
        for (int i = 1; i < MAXN; ++i) {
            if (!dfn[i]) {
                tarjan(i, i);
                ++cnt;
            }
        }
        vector<int> ans;
        for (int i = 1; i < MAXN; ++i) {
            if (num[i]) ans.push_back(i);
        }
        printf("Network #%d\n", ++kase);
        if (ans.size()) {
            for (int i = 0; i < ans.size(); ++i) {
                printf("  SPF node %d leaves %d subnets\n", ans[i], num[ans[i]] + cnt);
            }
        }
        else puts("  No SPF nodes");
        putchar('\n');
    }
    return 0;
}
