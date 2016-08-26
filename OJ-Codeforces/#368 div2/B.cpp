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
const int MAXN = 1e5 + 111;

struct P {
    int to;
    ll w;
};
bool is[MAXN];
vector<P> G[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int u, v, w, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(P{v, w});
        G[v].push_back(P{u, w});
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        is[x] = 1;
    }
    ll ans = INF;
    if (k != n) {
        for (int i = 1; i <= n; ++i) {
            if (is[i]) {
                for (int j = 0; j < G[i].size(); ++j) {
                    P &t = G[i][j];
                    if (!is[t.to]) {
                        ans = min(ans, t.w);
                    }
                }
            }
        }
    }
    if (ans == INF) printf("-1\n");
    else printf("%I64d\n", ans);
    return 0;
}
