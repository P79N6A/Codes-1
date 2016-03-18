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

struct Edge{
    int to, next, c;
}edge[MAXN * 2];
bool vis[MAXN];
int head[MAXN], tot, ans;

void add_edge(int u, int v, int c) {
    edge[tot].to = v;
    edge[tot].c = c;
    edge[tot].next = head[u];
    head[u] = tot++;
}

bool dfs(int a, int b, int c) {
    if (a == b) {
        ++ans;
        return 1;
    }
    vis[a] = 1;
    for (int i = head[a]; ~i; i = edge[i].next) {
        if (vis[edge[i].to]) continue;
        if (edge[i].c == c && dfs(edge[i].to, b, c)) return 1;
    }

    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, q, u, v, c, a, b;
    cin >> n >> m;
    memset(head, -1, sizeof head);
    tot = 0;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    cin >> q;
    while (q --) {
        cin >> a >> b;
        ans = 0;
        for (int i = 1; i <= 100; ++i) {
            memset(vis, 0, sizeof vis);
            dfs(a, b, i);
        }
        cout << ans << '\n';
    }
    return 0;
}
