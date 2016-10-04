#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 11;
const int MAXM = 1e5 + 11;

int n, m, s, t, k;
struct Edge {
    int to, w, nxt;
}edge[MAXM], redge[MAXM];
int head[MAXN], rhead[MAXN], tol;

void init() {
    memset(head, -1, sizeof head);
    memset(rhead, -1, sizeof rhead);
    tol = 0;
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].nxt = head[u];
    head[u] = tol;

    redge[tol].to = u;
    redge[tol].w = w;
    redge[tol].nxt = rhead[v];
    rhead[v] = tol++;
}

bool in[MAXN];
int dis[MAXN];
void spfa(int src) {
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        in[i] = 0;
    }
    queue<int> q;
    q.push(src);
    in[src] = 1;
    dis[src] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = rhead[u]; ~i; i = redge[i].nxt) {
            int v = redge[i].to, w = redge[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

struct A
{
    int f, g, v; // f = g + dis
    bool operator <(const A a)const {
        if(a.f == f) return a.g < g;
        return a.f < f;
    }
};
int astar(int src, int des) {
    int cnt = 0;
    priority_queue<A> pq;
    if (src == des) ++k; // 题意要求
    if (dis[src] == INF) return -1;
    A nxt;
    nxt.v = src, nxt.g = 0, nxt.f = nxt.g + dis[nxt.v];
    pq.push(nxt);
    while (pq.size()) {
        A cur = pq.top(); pq.pop();
        if (cur.v == des && ++cnt == k) {
            return cur.g;
        }
        for (int i = head[cur.v]; ~i; i = edge[i].nxt) {
            nxt.v = edge[i].to;
            nxt.g = cur.g + edge[i].w;
            nxt.f = nxt.g + dis[nxt.v];
            pq.push(nxt);
        }
    }
    return -1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v, w;
    while (~scanf("%d%d", &n, &m)) {
        init();
        while (m --) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        scanf("%d%d%d", &s, &t, &k);
        spfa(t);
        printf("%d\n", astar(s, t));
    }
    return 0;
}
