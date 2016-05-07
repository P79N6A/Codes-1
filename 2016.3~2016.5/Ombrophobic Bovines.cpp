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

const int MAXN = 510;//点数的最大值
const int MAXM = 540010;//边数的最大值
const long long INF = 1e16;

struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
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

int have[MAXN], can[MAXN], f, sum;
ll mp[MAXN][MAXN];

void build(ll up) {
    init();
    for (int i = 1; i <= f; ++i) {
        addedge(src, i, have[i]);
        addedge(i + f, des, can[i]);
        addedge(i, i + f, sum);
        for (int j = i + 1; j <= f; ++j) {
            if (mp[i][j] <= up) {
                addedge(i, j + f, sum);
                addedge(j, i + f, sum);
            }
        }
    }
}

int main()
{
    int m;
    while (~scanf("%d%d", &f, &m)) {
        sum = 0;
        for (int i = 1; i <= f; ++i) {
            scanf("%d%d", &have[i], &can[i]);
            sum += have[i];
        }
        int u, v, w;
        for (int i = 1; i <= f; ++i)
            for (int j = 1; j <= f; ++j)
                mp[i][j] = INF;

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            if (w < mp[u][v])
                mp[u][v] = mp[v][u] = w;
        }

        src = 0, des = 2 * f + 1;
        for (int i = 1; i <= f; ++i) {
            for (int j = 1; j <= f; ++j) {
                for (int k = 1; k <= f; ++k)
                    mp[j][k] = min(mp[j][i] + mp[i][k], mp[j][k]);
            }
        }

        ll ans = -1;
        ll l = 1, r = INF - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            build(mid);
            if (sap(src, des, des + 1) >= sum) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
