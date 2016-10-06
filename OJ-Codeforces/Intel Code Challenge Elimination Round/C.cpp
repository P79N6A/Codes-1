#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 11;

ll a[MAXN];
ll ans[MAXN];
ll sum[MAXN];
bool ok[MAXN];
int par[MAXN];
int x[MAXN];

int fnd(int x) {
    return x == par[x] ? x : par[x] = fnd(par[x]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        memset(sum, 0, sizeof sum);
        memset(ok, 0, sizeof ok);
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i]);
            par[i] = i;
        }
        par[n + 1] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
        }
        ll mx = 0;
        for (int i = n; i >= 1; --i) {
            int p = x[i];
            ans[i] = mx;
            int u = fnd(p - 1);
            int v = fnd(p + 1);
            sum[p] = a[p] + sum[u] + sum[v];
            if (ok[u])
                par[u] = p;
            if (ok[v])
                par[v] = p;
            ok[p] = 1;
            mx = max(mx, sum[p]);
        }
        for (int i = 1; i <= n; ++i) {
            printf("%I64d\n", ans[i]);
        }
    }
    return 0;
}
