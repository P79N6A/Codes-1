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

const int INF = 0x3f3f3f3f;
const int MAXN = 511;

struct Edge {
    int to, nxt, w;
}edge[MAXN * MAXN];
int head[MAXN];
int dis[MAXN], disp[MAXN], sta[MAXN], top, num[MAXN], people[MAXN], tol, pre[MAXN];
int ans[MAXN], cnt = 0;
int n, m, s, d;

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

void spfa() {
    memset(dis, 0x3f, sizeof dis);
    memset(disp, 0, sizeof disp);
    memset(num, 0, sizeof num);
    disp[s] = people[s];
    dis[s] = 0;
    num[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == d) continue;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                disp[v] = disp[u] + people[v];
                pre[v] = u;
                if (!num[v]) {
                    q.push(v);
                }
                num[v] = num[u];
            }
            else if (dis[v] == dis[u] + edge[i].w) {
                if (disp[v] < disp[u] + people[v]) {
                    disp[v] = disp[u] + people[v];
                    pre[v] = u;
                }
                if (!num[v]) {
                    q.push(v);
                }
                num[v] += num[u];
            }
        }
        num[u] = 0;
    }
    pre[s] = -1;
    int temp = d;
    do {
        ans[cnt++] = temp;
        temp = pre[temp];
    } while(temp != -1);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; ++i) scanf("%d", &people[i]), head[i] = -1;
    tol = top = 0;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    spfa();

    printf("%d %d\n", num[d], disp[d]);
    for (int i = cnt - 1; i >= 0; --i) {
        printf("%d", ans[i]);
        if (i != 0) putchar(' ');
        else putchar('\n');
    }
    return 0;
}
