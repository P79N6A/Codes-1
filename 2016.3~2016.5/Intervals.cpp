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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;
const int MAXM = 2e5 + 111;

struct Edge {
    int to, next, w;
}edge[MAXM];

int head[MAXN], tol, dis[MAXN];

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

bool in[MAXN];
void spfa(int s) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] < dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
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
    int n, mi = INF, mx = 0, u, v, w;
    memset(head, -1, sizeof head);
    tol = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v + 1, w);
        mi = min(mi, u);
        mx = max(mx, v + 1);
    }
    for (int i = mi; i < mx; ++i) {
        addedge(i, i + 1, 0);
        addedge(i + 1, i, -1);
        dis[i] = -INF;
    }
    dis[mx] = -INF;

    spfa(mi);

    printf("%d\n", dis[mx]);
    return 0;
}
