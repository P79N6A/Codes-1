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

const int MAXN = 500;//点数的最大值
const int MAXM = 4e3;//边数的最大值
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

int in[MAXN], out[MAXN];
void init() {
    tol = 0;
    memset(head,-1,sizeof(head));
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        init();
        int n, m, u, v, id;
        scanf("%d%d", &n, &m);
        while (m --) {
            scanf("%d%d%d", &u, &v, &id);
            ++out[u];
            ++in[v];
            if (!id)
                addedge(u, v, 1);
        }

        bool flag = 0;
        int src = 0, des = n + 1, sum = 0;
        for (int i = 1; i <= n; ++i) {
            out[i] -= in[i];
            if (out[i] % 2 != 0) {
                flag = 1;
                break;
            }
            out[i] /= 2;
            if (out[i] > 0) {
                addedge(src, i, out[i]);
                sum += out[i];
            }
            else if (out[i] < 0)
                addedge(i, des, -out[i]);
        }

        if (flag) {
            printf("impossible\n");
            continue;
        }

        if (sum == sap(src, des, des + 1)) printf("possible\n");
        else printf("impossible\n");
    }
    return 0;
}
