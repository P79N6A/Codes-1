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

const int MAXN = 200;
const int MAXM = 2e4;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
}edge[MAXM];
int head[MAXN], tol, nk[60][60], mk[60][60], need[60], have[60];
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(need, 0, sizeof need);
    memset(have, 0, sizeof have);
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
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0;i < N;i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
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
                    q.push(v);
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

int main()
{
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k) && (n|m|k)) {
        init(n + m + 2);
        int s = 0, t = n + m + 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j)
                scanf("%d", &nk[i][j]), need[j] += nk[i][j];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= k; ++j)
                scanf("%d", &mk[i][j]), have[j] += mk[i][j];
        }

        bool flag = 0;
        int x = 0, ans = 0;
        for (int l = 1; l <= k; ++l) {
            tol = 0;
            memset(head, -1, sizeof head);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    scanf("%d", &x);
                    addedge(n + j, i, mk[j][l], x);
                }
            }

            for (int i = 1; i <= n; ++i) addedge(i, t, nk[i][l], 0);
            for (int i = 1; i <= m; ++i) addedge(s, i + n, mk[i][l], 0);

            int flow = minCostMaxflow(s, t, ans);
            if (flow < need[l]) flag = 1;
        }

        if (flag) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}

