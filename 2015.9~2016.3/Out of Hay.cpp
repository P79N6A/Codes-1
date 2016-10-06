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
const int N = 2e3 + 111;

struct E {
    int u, v, w;
    bool operator < (const E& t)const {
        return w < t.w;
    }
}edge[MAXN];

int p[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    sort(edge, edge + m);

    for (int i = 1; i <= n; ++i) p[i] = i;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int u = find(edge[i].u), v = find(edge[i].v);
        if (u == v) continue;
        p[u] = v;
        ans = max(ans, edge[i].w);
    }
    printf("%d\n", ans);
    return 0;
}
