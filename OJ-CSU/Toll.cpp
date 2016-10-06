/*
  https://zh.wikipedia.org/zh-tw/%E8%BE%9B%E6%99%AE%E6%A3%AE%E7%A9%8D%E5%88%86%E6%B3%95
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;
const double eps = 1e-9;

struct Edge {
    int to, nxt, c, d;
}edge[MAXN];
int head[20], tol, n;

void addedge(int u, int v, int c, int d) {
    edge[tol].to = v;
    edge[tol].c = c;
    edge[tol].d = d;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

inline void init() {
    memset(head, -1, sizeof head);
    tol = 0;
}

double dis[MAXN];
bool in[MAXN];
double spfa(double x) {
    for (int i = 1; i <= n; ++i) dis[i] = 1e12;
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    in[1] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            double c = edge[i].c, d = edge[i].d;
            int v = edge[i].to;
            if (dis[v] > dis[u] + c * x + d) {
                dis[v] = dis[u] + c * x + d;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[n];
}

double get(double l, double r) {
    return (r - l) * (spfa(l) + 4 * spfa((l + r) / 2) + spfa(r)) / 6;
}

double ans(double l, double r) {
    double mid = (l + r) / 2;
    double mmid = (mid + r) / 2;
    double lev1 = get(l, r), lev2 = get(l,mid), lev3 = get(mid, mmid), lev4 = get(mmid, r);
    if (fabs(lev1 - (lev2 + lev3 + lev4)) < eps) return lev1;
    else return ans(l, mid) + ans(mid, mmid) + ans(mmid, r);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, t, u, v, c, d;
    while (~scanf("%d%d%d", &n, &m, &t)) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &u, &v, &c, &d);
            addedge(u, v, c, d);
        }
        printf("%.8f\n", ans(0, t) / (double)t);
    }
    return 0;
}
