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

const int MAXN = 11100;//���������ֵ
const int MAXM = 240200;//���������ֵ������
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//ע����MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];

void init()
{
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

char s[111];
int w[111][111];
int a[10], b[10];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        init();
        scanf("%d%s", &n, s);
        int P = n * n;
        src = P + n + 11, des = src + 1;
        for (int i = 0; i < 10; ++i) scanf("%d%d", &a[i], &b[i]);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &w[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            addedge(P + i, des, a[s[i] - '0']);
            addedge(P + i, P + n + s[i] - '0', INF); // ѡ�˵�i���͵�ѡ��Ӧ������
            for (int j = i + 1; j < n; ++j) {
                ans += w[i][j] + w[j][i];
                addedge(src, cnt, w[i][j] + w[j][i]);
                addedge(cnt, P + i, INF); // ѡ�����ij���͵�ѡ��Ӧ��i��j
                addedge(cnt++, P + j, INF);
            }
        }
        for (int i = 0; i < 10; ++i) {
            addedge(P + n + i, des, b[i] - a[i]);
        }
        printf("Case #%d: %d\n", kase, ans - sap(src, des, des + 1));
    }
    return 0;
}
