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

const int MAXN = 1010;//点数的最大值
const int MAXM = 5e5;//边数的最大值
const int INF = 0x3f3f3f3f;

struct Edge{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];

void addedge(int u,int v,int w,int rw = 0)
{
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

int Q[MAXN];
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while(front != rear)
    {
        int u = Q[front++];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}

int S[MAXN];
int sap(int start,int end,int N)
{
    BFS(start,end);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            int inser;
            for(int i = 0;i < top;i++)
            if(Min > edge[S[i]].cap - edge[S[i]].flow)
            {
                Min = edge[S[i]].cap - edge[S[i]].flow;
                inser = i;
            }
            for(int i = 0;i < top;i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if(flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start)u = edge[S[--top]^1].to;
    }
    return ans;
}

int dis[MAXN];
bool in[MAXN];
void spfa(int s) {
    queue<int> q;
    memset(dis, 0x3f, sizeof dis);
    memset(in, 0, sizeof in);
    dis[s] = 0;
    in[s] = 1;
    q.push(s);
    while (q.size()) {
        int cur = q.front(); q.pop();
        in[cur] = 0;
        for (int i = head[cur]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            //pr(cur)pr(v)
            if (dis[v] > dis[cur] + edge[i].cap) {
                dis[v] = dis[cur] + edge[i].cap;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
}

void init() {
    tol = 0;
    memset(head,-1,sizeof(head));
}

int main()
{
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, z;
        while (m --) {
            scanf("%d%d%d", &x, &y, &z);
            if (x == y) continue;
            addedge(x, y, z, INF);
        }
        scanf("%d%d", &x, &y);

        spfa(x);
        for (int i = 1; i <= n; ++i) {
            for (int j = head[i]; ~j; j = edge[j].next) {
                int v = edge[j].to;
                if (edge[j].cap == INF) edge[j].cap = 0;
                if (edge[j].cap == 0) continue;
                if (dis[v] != dis[i] + edge[j].cap) edge[j].cap = 0;
                else edge[j].cap = 1;
            }
        }
        printf("%d\n", sap(x, y, n + 1));
    }
    return 0;
}

