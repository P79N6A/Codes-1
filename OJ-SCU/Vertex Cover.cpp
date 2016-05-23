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
const int MAXN = 5e2 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN * MAXN];
int head[MAXN], tol, ans, n;
bool connect[MAXN];
int child[MAXN];

void init() {
    memset(head, -1, sizeof head);
    tol = 0;
    ans = min(n, 30);
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void build(int u) {
    child[u] = connect[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v < 30) child[u] |= 1 << v;
        else connect[u] = 1;
    }
}

bool judge(int p, int choose, int num) {
    for (int i = p; i < 30; ++i) choose |= 1 << i;
    for (int i = 0; i < 30; ++i) {
        if (!(choose & (1 << i)) && (child[i] & choose) != child[i])
            return 1;
    }
    for (int i = 30; i < n; ++i) {
        if ((choose & child[i]) != child[i]) ++num;
    }
    if (num >= ans) return 1;
    return 0;
}

int lef(int p, int choose) {
    int ret = 0;
    for (int i = p; i < n; ++i) {
        if ((child[i] & choose) != child[i]) ++ret;
    }
    return ret;
}

void dfs(int p, int choose, int num) {
    if (judge(p, choose, num)) return;
    if (p >= n || p >= 30) {
        ans = min(ans, num + lef(p, choose));
        return;
    }
    dfs(p + 1, choose, num);
    if ((child[p] & choose) != child[p] || connect[p])
        dfs(p + 1, choose | (1 << p), num + 1);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, u, v;
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            --u, --v;
            addedge(u, v);
            addedge(v, u);
        }
        for (int i = 0; i < n; ++i) build(i);
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
