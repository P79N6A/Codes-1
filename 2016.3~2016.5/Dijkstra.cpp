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
const int MAXN = 1e5 + 111;

struct Edge {
    int next, to;
    ll w;
}edge[2 * MAXN];

int n, m, pre[MAXN], head[MAXN], tol = 0;
ll dis[MAXN];
bool in[MAXN];

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void spfa(int s) {
    queue<int> q;
    q.push(s);
    for (int i = 1; i <= n; ++i) {
        dis[i] = 1e12;
    }
    dis[s] = 0;
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                pre[v] = u;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v, w;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    spfa(1);
    if (dis[n] == 1e12) printf("-1\n");
    else {
        vector<int> ans;
        int cnt = n;
        while (pre[cnt] != 1) {
            ans.push_back(cnt);
            cnt = pre[cnt];
        }
        ans.push_back(cnt);
        printf("1");
        for (int i = ans.size() - 1; i >= 0; --i) printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}
