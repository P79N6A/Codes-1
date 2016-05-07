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

const int MAXN = 200;//点数的最大值
const int MAXM = 20000;//边数的最大值
const long long INF = 1e16;

bool ok[MAXM];

struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
int cnt, cntm;
int score[15];
int match[15][15];

void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
    memset(ok, 0, sizeof ok);
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

void build(int x) {
    init();
    for (int i = 1; i <= cnt; ++i) {
        addedge(src, i, score[i]);
    }
    for (int i = 1; i <= cntm; ++i) {
        addedge(cnt + i, des, 1);
    }

    for (int i = cnt; i > cnt - x; --i) {
        for (int j = i + 1; j <= cnt; ++j) {
            if (score[i] < score[j]) {
                addedge(i, match[i][j] + cnt, 1);
                ok[match[i][j]] = 1;
            }
        }
    }

    for (int i = 1; i <= cnt; ++i) {
        for (int j = i + 1; j <= cnt; ++j) {
            if (!ok[match[i][j]]) {
                addedge(i, match[i][j] + cnt, 1);
                addedge(j, match[i][j] + cnt, 1);
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    int kase;
    scanf("%d ", &kase);
    while (kase --) {

        getline(cin, s);
        stringstream ss(s);
        cnt = 0;
        int x;
        while (ss >> x) {
            score[++cnt] = x;
        }

        cntm = 0;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = i + 1; j <= cnt; ++j)
                match[i][j] = ++cntm;
        }

        int ans;
        src = 0, des = cnt + cntm + 1;
        for (ans = cnt; ans >= 1; --ans) {
            build(ans);
            if (sap(src, des, des + 1) == (cnt * (cnt - 1)) / 2) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}

