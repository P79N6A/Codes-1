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
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 250;
int N, m; //点的个数，点的编号从1到N
bool Graph[MAXN][MAXN];
bool g[MAXN][MAXN];
int a[MAXN], b[MAXN];
int Match[MAXN];
bool InQueue[MAXN],InPath[MAXN],InBlossom[MAXN];
int Head,Tail;
int Queue[MAXN];
int Start,Finish;
int NewBase;
int Father[MAXN],Base[MAXN];
int Count;//匹配数，匹配对数是Count/2
void CreateGraph()
{
    memset(Graph,false,sizeof(Graph));
    memset(g, 0, sizeof g);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&a[i],&b[i]);
        Graph[a[i]][b[i]] = Graph[b[i]][a[i]] = true;
        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }
}
void Push(int u)
{
    Queue[Tail] = u;
    Tail++;
    InQueue[u] = true;
}
int Pop()
{
    int res = Queue[Head];
    Head++;
    return res;
}
int FindCommonAncestor(int u,int v)
{
    memset(InPath,false,sizeof(InPath));
    while(true)
    {
        u = Base[u];
        InPath[u] = true;
        if(u == Start) break;
        u = Father[Match[u]];
    }
    while(true)
    {
        v = Base[v];
        if(InPath[v])break;
        v = Father[Match[v]];
    }
    return v;
}
void ResetTrace(int u)
{
    int v;
    while(Base[u] != NewBase)
    {
        v = Match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = true;
        u = Father[v];
        if(Base[u] != NewBase) Father[u] = v;
    }
}
void BloosomContract(int u,int v)
{
    NewBase = FindCommonAncestor(u,v);
    memset(InBlossom,false,sizeof(InBlossom));
    ResetTrace(u);
    ResetTrace(v);
    if(Base[u] != NewBase) Father[u] = v;
    if(Base[v] != NewBase) Father[v] = u;
    for(int tu = 1; tu <= N; tu++)
    if(InBlossom[Base[tu]])
    {
        Base[tu] = NewBase;
        if(!InQueue[tu]) Push(tu);
    }
}

void FindAugmentingPath()
{
    memset(InQueue,false,sizeof(InQueue));
    memset(Father,0,sizeof(Father));
    for(int i = 1;i <= N;i++)
    Base[i] = i;
    Head = Tail = 1;
    Push(Start);
    Finish = 0;
    while(Head < Tail)
    {
        int u = Pop();
        for(int v = 1; v <= N; v++)
        if(Graph[u][v] && (Base[u] != Base[v]) && (Match[u] != v))
        {
            if((v == Start) || ((Match[v] > 0) && Father[Match[v]] > 0))
                BloosomContract(u,v);
            else if(Father[v] == 0)
            {
                Father[v] = u;
                if(Match[v] > 0)
                Push(Match[v]);
                else
                {
                    Finish = v;
                    return;
                }
            }
        }
    }
}

void AugmentPath()
{
    int u,v,w;
    u = Finish;
    while(u > 0)
    {
        v = Father[u];
        w = Match[v];
        Match[v] = u;
        Match[u] = v;
        u = w;
    }
}

void Edmonds()
{
    memset(Match,0,sizeof(Match));
    for(int u = 1; u <= N; u++)
        if(Match[u] == 0)
        {
            Start = u;
            FindAugmentingPath();
            if(Finish > 0) AugmentPath();
        }
}

void PrintMatch()
{
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (Match[i] > 0) ++cnt;
    }
    cnt /= 2;

    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int tcnt = 0;
        memcpy(Graph, g, sizeof (g));
        for (int j = 1; j <= N; ++j) {
            Graph[a[i]][j] = Graph[j][a[i]] = Graph[b[i]][j] = Graph[j][b[i]] = 0;
        }
        Edmonds();
        for (int j = 1; j <= N; ++j) {
            if (Match[j] > 0) ++tcnt;
        }
        if (tcnt/2 != cnt - 1) ans.push_back(i + 1);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i != ans.size() - 1) putchar(' ');
    }
    putchar('\n');
}

int main()
{
    while (~scanf("%d%d",&N, &m)) {
        CreateGraph();//建图
        Edmonds();//进行匹配
        PrintMatch();//输出匹配数和匹配
    }
    return 0;
}
