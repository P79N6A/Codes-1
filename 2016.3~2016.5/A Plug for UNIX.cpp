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
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 400;//点数的最大值
const int MAXM = 2e5;//边数的最大值
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

void init() {
    tol = 0;
    memset(head,-1,sizeof(head));
}

string rec[110];
string plug[110];
string recc[110], plugg[110];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    string name;
    init();

    int src = 0, des = 302;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> rec[i];
        addedge(src, i, 1);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> name >> plug[i];
        addedge(i + n, des, 1);
        for (int j = 1; j <= n; ++j) {
            if (rec[j] == plug[i])
                addedge(j, i + n, 1);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> recc[i] >> plugg[i];
        for (int j = 1; j <= n; ++j) {
            if (rec[j] == plugg[i])
                addedge(j, i + n + m, 1);
        }
        for (int j = 1; j <= m; ++j) {
            if (plug[j] == recc[i])
                addedge(i + n + m, j + n, 1);
        }
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            if (recc[i] == plugg[j] || recc[j] == plugg[i])
                addedge(i + n + m, j + n + m, INF, INF);
        }
    }

    cout << m - sap(src, des, des + 1) << '\n';
    return 0;
}

