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
const int MAXN = 2e4 + 111;

struct E {
    int u, v, w;
    bool operator < (const E&t)const{
        return w > t.w;
    }
}edge[3 * MAXN];

int p[MAXN], rnk[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int unite(int x, int y, int w) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (rnk[x] > rnk[y]) p[y] = x;
    else {
        p[x] = y;
        if (rnk[x] == rnk[y]) ++rnk[y];
    }
    return w;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int n, m, r;
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i < n; ++i) p[i] = i, rnk[i] = 0;
        for (int j = 0; j < m; ++j) p[n + j] = n + j, rnk[n + j] = 0;

        for (int i = 0; i < r; ++i) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge, edge + r);

        int sum = 0;
        for (int i = 0; i < r; ++i) {
            int u = edge[i].u, v = edge[i].v;
            sum += unite(u, v + n, edge[i].w);
        }
        printf("%d\n", (m + n) * 10000 - sum);
    }
    return 0;
}
