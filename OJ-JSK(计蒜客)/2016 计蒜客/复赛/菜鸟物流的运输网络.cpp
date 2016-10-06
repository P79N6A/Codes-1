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

const int MAXN = 210;//点数的最大值
const int MAXM = 80010;//边数的最大值的两倍
const int INF = 0x3f3f3f3f;

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

vector<int> ans;
bool vis[MAXN];
int n, m, a, b, c, u, v;

void dfs(int u, int t, vector<int> temp) {
    vis[u] = 1;
    if (u == t) {
        ans = temp;
        return;
    }
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int tt = v;
        if (tt > n) tt -= n;
        if (edge[i].flow == 0 || vis[v]) continue;
        temp.push_back(tt);
        dfs(v, t, temp);
        temp.pop_back();
        vis[v] = 0;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        init();
        scanf("%d%d", &n, &m);
        scanf("%d%d%d", &a, &b, &c);
        src = c, des = 2 * n + 1;
        for (int i = 1; i <= n; ++i) {
            addedge(i, i + n, 1);
        }
        while (m --) {
            scanf("%d%d", &u, &v);
            addedge(u + n, v, 1);
            addedge(v + n, u, 1);
        }
        addedge(src, src + n, 1);
        addedge(a + n, des, 1);
        addedge(b + n, des, 1);
        int sum = sap(src, des, des + 1);
        //pr(sum)
        memset(vis, 0, sizeof vis);
        vis[des] = 1;

        vector<int> temp;
        dfs(a, b, temp);
        printf("%d", a);
        int pre = a;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] == pre) continue;
            printf(" %d", ans[i]);
            pre = ans[i];
        }
        putchar('\n');
    }
    return 0;
}
