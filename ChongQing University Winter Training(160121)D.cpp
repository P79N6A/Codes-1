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

struct P {
    int v, w;
    P(int b, int c): v(b),w(c){}
};
vector<P> edge[MAXN];
bool vis[MAXN];

int dfs(int x, int p) {
    if (vis[x] == 1) return 0;
    vis[x] = 1;
    int ret = 0;
    for (int i = 0; i < edge[x].size(); ++i) {
        int v = edge[x][i].v;
        if (v != p) {
            ret += edge[x][i].w + dfs(v, x);
        }
    }
    return ret;
}

int main()
{
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back(P(b, 0));
        edge[b].push_back(P(a, c));
    }
    int ans = INF;

    memset(vis, 0, sizeof vis);
    ans = min(dfs(1, edge[1][0].v), ans);

    memset(vis, 0, sizeof vis);
    ans = min(dfs(1, edge[1][1].v), ans);

    printf("%d\n", ans);
    return 0;
}
