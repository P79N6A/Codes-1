/*
 拆点，容量1，费用-1.然后对苹果排序，可行的苹果间连线，
 源点苹果连线，苹果汇点连线，超级源点与源点容量为2的线
*/
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

const int MAXN = 2e3 + 111;
const int MAXM = 2e6; // 边数最大值的两倍
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
}edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}

int sta[MAXN], top;
bool spfa(int s,int t)
{
    top = 0;
    for(int i = 0;i < N;i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    sta[top++] = s;
    while(top)
    {
        int u = sta[--top];
        vis[u] = false;
        for(int i = head[u]; i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost )
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
//                    printf("%d\n", v);
                    sta[top++] = v;
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
//返回的是最大流， cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t];i != -1;i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i].flow)
            Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t];i != -1;i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

struct P {
    int h, d;
    bool operator < (const P& t)const {
        if (h == t.h) return d < t.d;
        return h > t.h;
    }
    void read() {
        scanf("%d%d", &h, &d);
    }
}p[1111];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        init(2 * n + 3);
        for (int i = 0; i < n; ++i) {
            p[i].read();
        }
        sort(p, p + n);
        int s = 2 * n, ss = 2 * n + 1, t = 2 * n + 2;
        addedge(ss, s, 2, 0);
        for (int i = 0; i < n; ++i) {
            addedge(i, i + n, 1, -1);
            addedge(s, i, 1, 0);
            addedge(i + n, t, 1, 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (p[i].d <= p[j].d) {
                    addedge(i + n, j, 1, 0);
                }
            }
        }
        int cost = 0;
        minCostMaxflow(ss, t, cost);
        printf("%d\n", -cost);
    }
    return 0;
}
