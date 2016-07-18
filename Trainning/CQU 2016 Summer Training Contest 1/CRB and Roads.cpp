/*
 首先，如果A->B有直接的一条边连接且存在一条经由另外的点到达B的路线，那么这条路线，
 也就是A->B的直达是多余的。
 基于这个观察，要怎么判断呢？优先让长度长的路线访问，然后判断即可。怎么让长度长的
 路线先访问呢？拓扑序，然后逆向边标记该点已经被什么点访问。（链式前向星优先访问后
 加进去的结点哦~）
 PS:这里的长度长的路线可以理解为，偏序关系长的路线
 那么开始CODING！
*/
#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;
const int MAXM = 1e5 + 111;

struct Edge {
    int to, next;
}edge[2][MAXM];
int head[2][MAXN], tol[2];
int deg[MAXN];

void init(int n) {
    tol[0] = tol[1] = 0;
    for (int i = 1; i <= n; ++i) {
        head[0][i] = head[1][i] = -1;
        deg[i] = 0;
    }
}

void addedge(int u, int v, int who) {
    edge[who][tol[who]].to = v;
    edge[who][tol[who]].next = head[who][u];
    head[who][u] = tol[who]++;
}

int que[MAXN], l, r;
bitset<MAXN> bit[MAXN];
void topo(int n) {
    l = r = 0;
    for (int i = 1; i <= n; ++i) {
        bit[i].reset();
        bit[i][i] = 1;
        if (deg[i] == 0) {
            que[r++] = i;
            --deg[i];
        }
    }
    while (l < r) {
        int u = que[l++];
        for (int i = head[0][u]; ~i; i = edge[0][i].next) {
            int v = edge[0][i].to;
            if (--deg[v] == 0) {
                que[r++] = v;
            }
            addedge(v, u, 1);
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, u, v; scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v, 0);
            ++deg[v];
        }
        topo(n);
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            u = que[i];
            for (int j = head[1][u]; ~j; j = edge[1][j].next) {
                v = edge[1][j].to;
                if (bit[u][v]) ++ans;
                bit[u] |= bit[v];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
