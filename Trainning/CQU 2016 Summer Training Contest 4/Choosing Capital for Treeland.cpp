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
const int MAXN = 2e5 + 111;

struct Edge {
    int to, w, nxt;
}edge[MAXN * 2];
int head[MAXN], tol;

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

int dp[MAXN];

void dfs(int u, int f) {
    dp[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs(v, u);
        dp[u] += dp[v] + edge[i].w;
    }
}

int mi = INF;

void rebuild(int u, int f) {
    mi = min(dp[u], mi);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        if (edge[i].w) {
            dp[v] = dp[u] - 1;
        }
        else dp[v] = dp[u] + 1;
        rebuild(v, u);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, u, v;
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addedge(u, v, 0);
        addedge(v, u, 1);
    }
    dfs(1, 1);
    rebuild(1, 1);
    printf("%d\n", mi);
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == mi) printf("%d ", i);
    }
    return 0;
}
