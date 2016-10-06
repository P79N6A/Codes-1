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

vector<int> G[MAXN];
int deg[MAXN], p[MAXN];

int fp(int x) {
    return x == p[x] ? x : p[x] = fp(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m);
        int u, v;
        for (int i = 1; i <= n; ++i) G[i].clear(), deg[i] = 0, p[i] = i;
        while (m --) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            ++deg[u];
            ++deg[v];
            u = fp(u);
            v = fp(v);
            if (u != v) p[u] = p[v];
        }

        int ok = 1, j = fp(1);
        for (int i = 1; i <= n; ++i) {
            if (deg[i] % 2 || fp(i) != j) {
                ok = 0;
                break;
            }
        }
        printf("%d\n", ok);
    }
    return 0;
}
