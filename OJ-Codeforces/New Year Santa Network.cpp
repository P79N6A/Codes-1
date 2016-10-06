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
const int MAXN = 1e5 + 111;

struct Edge {
    int to, next, w;
}edge[MAXN * 2];
int head[MAXN], tol;
int u[MAXN], v[MAXN], w[MAXN];
double sz[MAXN];

void addedge(int u, int v, int w) {
    edge[tol].next = head[u];
    edge[tol].w = w;
    edge[tol].to = v;
    head[u] = tol++;
}

double dfs(int u, int f) {
    sz[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == f) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

double getSum(ll n) {
    dfs(1, -1);
    double ret = 0;
    for (int i = 1; i < n; ++i) {
        double mi = min(sz[u[i]], sz[v[i]]);
        ret += 2 * w[i] * mi * (n - mi);
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n;
    scanf("%I64d", &n);
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        addedge(u[i], v[i], w[i]);
        addedge(v[i], u[i], w[i]);
    }
    double ans = getSum(n);
    double div = n * (n - 1);
    int q, x, y;
    scanf("%d", &q);
    while (q --) {
        scanf("%d%d", &x, &y);
        double mi = min(sz[u[x]], sz[v[x]]);
        ans -= 2 * (w[x] - y) * mi * (n - mi);
        printf("%.10f\n", 3 * ans / div);
        w[x] = y;
    }
    return 0;
}
