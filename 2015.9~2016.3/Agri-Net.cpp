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
const int MAXN = 111;

struct E {
    int u, v, w;
    bool operator < (const E&t)const {
        return w < t.w;
    }
}edge[MAXN * MAXN];

int p[MAXN], rnk[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    int n;
    while (~scanf("%d", &n)){
        int x, cnt = 0;
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x);
                edge[cnt].u = i, edge[cnt].v = j, edge[cnt++].w = x;
            }
        }
        sort(edge, edge + cnt);

        int sum = 0;
        for (int i = 0; i < cnt; ++i) {
            int u = edge[i].u, v = edge[i].v;
            u = find(u), v = find(v);
            if (u != v) {
                sum += edge[i].w;
                p[u] = v;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
