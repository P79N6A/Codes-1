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
const int MAXN = 511;

struct E {
    int u, v, w;
    bool operator < (const E& t)const {
        return w < t.w;
    }
}edge[MAXN * MAXN];

int p[MAXN], mp[MAXN][MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edge[cnt].u = i;
                edge[cnt].v = j;
                edge[cnt++].w = mp[i][j];
            }
        }
        sort(edge, edge + cnt);
        int ans = 0;
        for (int i = 0; i < cnt; ++i) {
            int u = find(edge[i].u), v = find(edge[i].v);
            if (u != v) {
                p[u] = v;
                ans = max(ans, edge[i].w);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
