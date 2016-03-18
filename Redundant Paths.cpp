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
const int MAXN = 5e3 + 111;

struct Edge {
    int to, next;
    bool cut;
}edge[MAXN];
int head[MAXN], tot;
int low[MAXN], dfn[MAXN], Stack[MAXN], Belong[MAXN];
int index, top;
int block;
bool inStack[MAXN];
int bridge;

void add_edge(int u, int v) {
    edge[tot].to = v;
    edge[tot].cut = 0;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u, int fa) {
    int v;
    low[u] = dfn[u] = ++index;
    Stack[top++] = u;
    inStack[u] = 1;

    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (v == fa) continue;
        if (!dfn[v]) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) { // low[v] < dfn[u]说明子结点能到达u的父节点，也就是形成环了
                ++bridge;
                edge[i].cut = edge[i^1].cut = 1;
            }
        }
        else if (inStack[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) { // 缩点
        ++block;
        do {
            v = Stack[--top];
            inStack[v] = 0;
            Belong[v] = block;
        }while (v != u);
    }
}

int deg[MAXN];

int main()
{
    int f, r, u, v;
    tot = 0;
    scanf("%d%d", &f, &r);
    memset(head, -1, sizeof head);
    while (r --) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    memset(dfn, 0, sizeof dfn);
    memset(inStack, 0, sizeof inStack);
    index = top = block = 0;

    Tarjan(1, 0);

    int ans = 0;
    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= f; ++i) {
        for (int j = head[i]; ~j; j = edge[j].next) {
            if (edge[j].cut) ++deg[Belong[i]]; // 新图中，割边就是连结所有点的边
        }
    }

    for (int i = 1; i <= block; ++i) if (deg[i] == 1) ++ans;

    printf("%d\n", (ans + 1) / 2);
    return 0;
}
