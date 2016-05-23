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
const int MAXN = 111;
const int MAXM = 111*111;

struct Edge {
    int u, v, w;
    bool del, equ, use;
    bool operator < (const Edge& t)const {
        return w < t.w;
    }
}edge[MAXM];

int par[MAXN], n, m, first = 0;

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int kruskal() {
    for (int i = 1; i <= n; ++i) par[i] = i;
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        if (edge[i].del) continue;
        int u = find(edge[i].u), v = find(edge[i].v);
        if (u == v) continue;
        par[u] = v;
        ret += edge[i].w;
        if (first) edge[i].use = 1;
    }
    return ret;
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
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].del = 0;
            edge[i].use = 0;
            edge[i].equ = 0;
            for (int j = 0; j < i; ++j) {
                if (edge[i].w == edge[j].w)
                    edge[i].equ = edge[j].equ = 1;
            }
        }
        sort(edge, edge + m);
        first = 1;
        int ans = kruskal();
        first = 0;
        bool flag = 1;
        for (int i = 0; i < m; ++i) {
            if (edge[i].use && edge[i].equ) {
                edge[i].del = 1;
                if (ans == kruskal()) {
                    puts("Not Unique!");
                    flag = 0;
                    break;
                }
                edge[i].del = 0;
            }
        }
        if (flag) printf("%d\n", ans);
    }
    return 0;
}
