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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1e3;//点数的最大值
const int MAXM = 5000;//边数的最大值的两倍
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
bool l[MAXN], r[MAXN];
int u[MAXN], v[MAXN];

void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1;i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}

void dfsl(int x) {
    if (l[x]) return;
    l[x] = 1;
    for (int i = head[x]; ~i; i = edge[i].next) {
        if (edge[i].cap > edge[i].flow && !l[edge[i].to]) {
            dfsl(edge[i].to);
        }
    }
}

void dfsr(int x) {
    if (r[x]) return;
    r[x] = 1;
    for (int i = head[x]; ~i; i = edge[i].next) {
        if (edge[i^1].cap > edge[i^1].flow && !r[edge[i].to]) {
            //printf("%d -> %d, cap = %d, flow = %d\n", x, edge[i].to, edge[i].cap, edge[i].flow);
            dfsr(edge[i].to);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, p;
    while (~scanf("%d%d%d", &n, &m, &p) && n) {
        init();
        des = 0, src = n + m + 2;
        int w;
        for (int i = 0; i < p; ++i) {
            scanf("%d%d%d", &u[i], &v[i], &w);
            addedge(u[i], v[i], w);
        }
        for (int i = 1; i <= n; ++i) addedge(src, i, INF);
        int sp = sap(src, des, n + m + 5);
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        dfsl(src);
        dfsr(des);
        bool first = 0;
        for (int i = 0; i < p; ++i) {
            if (((l[u[i]] && r[v[i]]) || (l[v[i]] && r[u[i]])) && edge[i * 2].flow == edge[i * 2].cap) {
                if (!first) first = 1;
                else putchar(' ');
                printf("%d", i + 1);
            }
        }
        putchar('\n');
    }
    return 0;
}
