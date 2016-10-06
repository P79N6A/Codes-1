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

const int INF = 0x3f3f3f3f;
const int MAXN = 2e6 + 111;

int dis[1111], height[1111], head[1111], s, t, tol = 0, org;

struct Edge {
    int from, to, next, h, w;
}edge[MAXN];

void addedge(int u, int v, int h, int w) {
    edge[tol].from = u;
    edge[tol].next = head[u];
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].h = h;
    head[u] = tol++;
}

bool in[1111];
void spfa() {
    memset(in, 0, sizeof in);
    memset(height, 0, sizeof height);
    queue<int> q;
    q.push(s);
    height[s] = org;
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int cmp = min(height[u], edge[i].h);
            if (height[v] < cmp) {
                height[v] = cmp;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
}

void spfa2() {
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            if (edge[i].h < height[t]) continue;
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, r, kase = 0;
    while (~scanf("%d%d", &n, &r) && (n|r)) {
        if (kase) printf("\n");
        memset(head, -1, sizeof head);
        tol = 0;
        int u, v, h, w;
        for (int i = 0; i < r; ++i) {
            scanf("%d%d%d%d", &u, &v, &h, &w);
            if (h == -1) h = INF;
            addedge(u, v, h, w);
            addedge(v, u, h, w);
        }
        scanf("%d%d%d", &s, &t, &org);

        spfa();

        printf("Case %d:\n", ++kase);
        if (height[t] == 0) printf("cannot reach destination\n");
        else {
            spfa2();
            printf("maximum height = %d\n", height[t]);
            printf("length of shortest route = %d\n", dis[t]);
        }
    }
    return 0;
}
