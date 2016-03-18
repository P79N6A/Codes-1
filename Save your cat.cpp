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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;
const int M = 1e8 + 111;

struct E {
    int u, v;
    double w;
    bool operator < (const E&t)const {
        return w > t.w;
    }
}edge[M];

int p[MAXN];
double x[MAXN], y[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

double getdis(int a, int b) {
    double xx = x[a] - x[b], yy = y[a] - y[b];
    return sqrt(xx * xx + yy * yy);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]), p[i] = i;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &edge[i].u, &edge[i].v);
        edge[i].w = getdis(edge[i].u, edge[i].v);
    }

    sort(edge, edge + m);

    double sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += edge[i].w;
        int u = edge[i].u, v = edge[i].v;
        u = find(u), v = find(v);
        if (u != v) {
            sum -= edge[i].w;
            p[u] = v;
        }
    }
    printf("%.4f\n", sum);
    return 0;
}
