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
const int MAXN = 1e3 + 111;
const int MAXM = 3e5 + 111;

struct Edge{
    int next, to, w;
}edge[MAXM];

int head[2 * MAXN], tol;

void addedge(int u, int v, int w) {
    edge[tol].next = head[u];
    edge[tol].to = v;
    edge[tol].w = w;
    head[u] = tol++;
}

int dis[MAXN], num[MAXN];
bool in[MAXN];
bool spfa(int n, int s) {
    for (int i = 1; i <= n; ++i) {
        dis[i] = -INF;
        in[i] = num[i] = 0;
        addedge(s, i, 0);
    }
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    in[s] = 1;
    ++num[s];
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] < dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                    if (++num[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n, m, a, b, c;
    char op[2];
    while (~scanf("%d%d", &n, &m)) {
        memset(head, -1, sizeof head);
        tol = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'P') {
                scanf("%d", &c);
                addedge(a, b, c);
                addedge(b, a, -c);
            }
            else {
                addedge(a, b, 1);
            }
        }

        if (spfa(n, 0)) printf("Unreliable\n");
        else printf("Reliable\n");
    }
    return 0;
}
