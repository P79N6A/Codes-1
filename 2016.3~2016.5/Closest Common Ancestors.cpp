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
const int MAXN = 1e3 + 111;
const int MAXM = 8e5;

struct Query {
    int to, next, id;
}query[2 * MAXM];
int head[MAXN], tol = 0;

vector<int> G[MAXN];
int cnt[MAXN], ancestor[MAXN];
int ans[MAXM];
bool isLeaf[MAXN], vis[MAXN];
int n;

int find(int x) {
    return ancestor[x] == x ? x : ancestor[x] = find(ancestor[x]);
}

void init() {
    tol = 0;
    for (int i = 0; i <= n; ++i) {
        isLeaf[i] = cnt[i] = vis[i] = 0;
        head[i] = -1;
        G[i].clear();
    }
}

void addedge(int u, int v, int indx) {
    query[tol].to = v;
    query[tol].next = head[u];
    query[tol].id = indx;
    head[u] = tol++;
}

void lca(int u) {
    ancestor[u] = u;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v]) continue;
        lca(v);
        ancestor[v] = u;
    }

    for (int i = head[u]; ~i; i = query[i].next) {
        int v = query[i].to;
        if (vis[v]) {
            ans[query[i].id] = ancestor[find(v)];
        }
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        init();
        int u, v, x;
        for (int i = 0; i < n; ++i) {
            scanf("%d:(%d)", &u, &x);
            for (int j = 0; j < x; ++j) {
                scanf("%d", &v);
                isLeaf[v] = 1;
                G[u].push_back(v);
            }
        }
        scanf("%d", &x);
        for (int i = 0; i < x; ++i) {
            scanf(" (%d %d)", &u, &v);
            addedge(u, v, i);
            addedge(v, u, i);
        }

        for (int i = 1; i <= n; ++i) {
            if (!isLeaf[i]) {
                lca(i);
                break;
            }
        }

        for (int i = 0; i < x; ++i) {
            ++cnt[ans[i]];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] > 0) {
                printf("%d:%d\n", i, cnt[i]);
            }
        }
    }
    return 0;
}
