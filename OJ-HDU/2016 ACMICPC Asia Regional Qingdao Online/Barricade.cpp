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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1e3 + 11;//���������ֵ
const int MAXM = 2e4 + 222;//���������ֵ������
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//ע����MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];

vector<pii> G[MAXN];
bool in[MAXN];
int dis[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; ++i) G[i].clear(), dis[i] = INF, in[i] = 0;
    tol = 0;
    memset(head,-1,sizeof(head));
}
//�ӱߣ�����ͼ����������˫��ͼ�ĸ�����
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
//�����������㡢�յ㡢�������
//��ı��û��Ӱ�죬ֻҪ����������
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

void spfa(int s) {
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            pii temp = G[u][i];
            int v = temp.first, w = temp.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v, w;
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }
        spfa(1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < G[i].size(); ++j) {
            }
        }
    }
    return 0;
}

