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
const int MAXN = 1e3 + 111;
const int M = 2e4 + 111;

struct E {
    int u, v, w;
    bool operator < (const E&t)const {
        return w > t.w;
    }
}edge[M];

int p[MAXN], rnk[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    sort(edge, edge + m);

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        u = find(u), v = find(v);
        if (u != v) {
            sum += edge[i].w;
            p[u] = v;
        }
    }
    int f = find(1);
    for (int i = 2; i <= n; ++i) if (f != find(i)) sum = -1;
    printf("%d\n", sum);
    return 0;
}
