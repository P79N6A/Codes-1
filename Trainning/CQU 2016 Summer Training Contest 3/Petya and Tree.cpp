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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

double val[MAXN];
double mi[MAXN], mx[MAXN];
double dp[MAXN], dep[MAXN];
int l[MAXN], r[MAXN];
vector<pii> sv;

void dfs(int u) {
    mi[u] = mx[u] = val[u];
    if (l[u]) {
        dfs(l[u]);
        int v = l[u];
        mi[u] = min(mi[u], mi[v]);
    }
    if (r[u]) {
        dfs(r[u]);
        int v = r[u];
        mx[u] = max(mx[u], mx[v]);
    }
}

void init(int u, int de) {
    dep[u] = de;
    if (l[u]) {
        dp[l[u]] = dp[u] + mi[r[u]];
        init(l[u], de + 1);
    }
    if (r[u]) {
        dp[r[u]] = dp[u] + mx[l[u]];
        init(r[u], de + 1);
    }
}

int par[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, p, k, rt; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%lf", &par[i], &val[i]);
        if (par[i] == -1) rt = i;
    }
    for (int i = 1; i <= n; ++i) {
        sv.push_back(make_pair(val[i], i));
        p = par[i];
        if (p == -1) continue;
        if (val[i] < val[p]) l[p] = i;
        else r[p] = i;
    }
    dfs(rt);
    dp[rt] = 0;
    init(rt, 0);
    scanf("%d", &k);
    sort(sv.begin(), sv.end());
    while (k --) {
        scanf("%d", &p);
        int u = 0;
        int x = upper_bound(sv.begin(), sv.end(), make_pair(p, 0)) - sv.begin();
        if (x) --x;
        u = sv[x].second;
        while (1) {
            if (!l[u] || !r[u]) break;
            if (p > val[u]) u = r[u];
            else u = l[u];
        }
        printf("%.10f\n", dp[u] / dep[u]);
    }
    return 0;
}
