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
const int MAXN = 4e5 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int head[MAXN], tol;
int sz[MAXN], n, mx[MAXN];
bool is[MAXN];

inline void init() {
    memset(head, -1, sizeof head);
    tol = 0;
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void dfs(int u, int f) {
    is[u] = 1;
    sz[u] = 1;
    mx[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
    }
    if (sz[u] <= n / 2) mx[u] = max(mx[u], sz[u]);
}

// upMx:保留上方子树中，不大于n/2的最结点个数
void getans(int u, int f, int upMx) {
    vector<pii> vc;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        vc.push_back(pii(mx[v], v));
    }
    sort(vc.begin(), vc.end(), greater<pii>() );
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        int nxUpMx = upMx;
        if (n - sz[v] <= n / 2) nxUpMx = max(nxUpMx, n - sz[v]);
        if (v == vc[0].second) {
            if (vc.size() > 1) {
                nxUpMx = max(nxUpMx, vc[1].first);
            }
        }
        else nxUpMx = max(nxUpMx, vc[0].first);
        // 子节点不论如何都满足不了<=n/2，所以肯定父结点也不行
        if (sz[v] - mx[v] > n / 2) {
            is[u] = 0;
        }
        getans(v, u, nxUpMx);
    }
    if (n - sz[u] - upMx > n / 2) is[u] = 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, 1);
        getans(1, 1, 0);
        printf("%d", is[1]);
        for (int i = 2; i <= n; ++i) {
            printf(" %d", is[i]);
        }
        putchar('\n');
    }
    return 0;
}
