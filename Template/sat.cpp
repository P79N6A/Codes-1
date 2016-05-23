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

const int INF = 0x7f7f7f7f;
const int MAXM = 4e4 + 111;
const int MAXN = 2e4 + 111;

struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值1~scc
int Index,top;
int scc;
bool Instack[MAXN];
int num[MAXN];
void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
    v = edge[i].to;
    if( !DFN[v] )
    {
    Tarjan(v);
    if(Low[u] > Low[v])Low[u] = Low[v];
    }
    else if(Instack[v] && Low[u] > DFN[v])
    Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }while(v != u);
    }
}
bool solvable(int n)//n是总个数,需要选择一半
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for(int i = 0;i < n;i++)
    if(!DFN[i])
    Tarjan(i);
    for(int i = 0;i < n;i += 2)
    {
    if(Belong[i] == Belong[i^1])
    return false;
    }
    return true;
}
//*************************************************
//拓扑排序求任意一组解部分
queue<int>q1,q2;
vector<vector<int> > dag;//缩点后的逆向DAG图
char color[MAXN];//染色，为'R'是选择的
int indeg[MAXN];//入度
int cf[MAXN];
void solve(int n)
{
    dag.assign(scc+1,vector<int>());
    memset(indeg,0,sizeof(indeg));
    memset(color,0,sizeof(color));
    for(int u = 0;u < n;u++)
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(Belong[u] != Belong[v])
        {
            dag[Belong[v]].push_back(Belong[u]);
            indeg[Belong[u]]++;
        }
    }
    for(int i = 0;i < n;i += 2)
    {
        cf[Belong[i]] = Belong[i^1];
        cf[Belong[i^1]] = Belong[i];
    }
    while(!q1.empty())q1.pop();
    while(!q2.empty())q2.pop();
    for(int i = 1;i <= scc;i++)
    if(indeg[i] == 0)
    q1.push(i);
    while(!q1.empty())
    {
        int u = q1.front();
        q1.pop();
        if(color[u] == 0)
        {
            color[u] = 'R';
            color[cf[u]] = 'B';
        }
        int sz = dag[u].size();
        for(int i = 0;i < sz;i++)
        {
            indeg[dag[u][i]]--;
            if(indeg[dag[u][i]] == 0)
            q1.push(dag[u][i]);
        }
    }
}
int change(char s[])
{
    int ret = 0;
    int i = 1;
    while(s[i]>='0' && s[i]<='9')
    {
        ret *= 10;
        ret += s[i]-'0';
        i++;
    }
    --ret;
    if(s[0] == '+')return 2*ret;
    else return 2*ret+1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, kase = 0, n, m; scanf("%d", &t);
    char s[10];
    while (t --) {
        scanf("%d%d", &m, &n);
        init();
        while (m --) {
            scanf("%s", s);
            int u = change(s);
            scanf("%s", s);
            int v = change(s);
            addedge(u^1, v);
            addedge(v^1, u);
        }
        printf("Case %d: ", ++kase);
        if (solvable(2 * n)) {
            puts("Yes");
            solve(2 * n);
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (color[Belong[2 * i]] == 'R') {
                    ++ans;
                }
            }
            printf("%d", ans);
            for (int i = 0; i < n; ++i) {
                if (color[Belong[2 * i]] == 'R') {
                    printf(" %d", i + 1);
                }
            }
            putchar('\n');
        }
        else puts("No");
    }
    return 0;
}
