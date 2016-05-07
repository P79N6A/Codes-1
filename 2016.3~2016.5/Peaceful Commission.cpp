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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;
const int MAXM = 1e5;

struct Edge {
    int to, nxt;
}edge[MAXM];
int head[MAXN], tol;

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

bool vis[MAXN];
int sta[MAXN], top;
bool dfs(int u) {
    if (vis[u ^ 1]) return 0;
    if (vis[u]) return 1;
    vis[u] = 1;
    sta[top++] = u;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        if (!dfs(edge[i].to)) return 0;
    }
    return 1;
}

bool twoSat(int n) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i += 2) {
        if (vis[i] || vis[i ^ 1]) continue;
        top = 0;
        if (!dfs(i)) {
            while(top) vis[sta[--top]] = 0;
            if (!dfs(i ^ 1)) return 0;
        }
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        init();
        int u, v;
        while (m --) {
            scanf("%d%d", &u, &v);
            --u; --v;
            addedge(u, v^1);
            addedge(v, u^1);
        }
        if (twoSat(2 * n)) {
            for (int i = 0; i < 2 * n; ++i) {
                if (vis[i]) printf("%d\n", i + 1);
            }
        }
        else printf("NIE\n");
    }
    return 0;
}
