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

const int MAXN = 1010;//点数的最大值
const int MAXM = 540010;//边数的最大值
const int INF = 0x3f3f3f3f;

struct Edge{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
//ans:蜥蜴个数 cnt:点的id
int tol, n, k, ans, cnt, len, s, t;
int id[30][30]; // 存点ID
char mp[30][30], liz[30][30];
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
    scanf("%d%d", &n, &k);
    tol = 0, ans = 0;
    memset(head,-1,sizeof(head));
    memset(id, 0, sizeof id);
    for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
    for (int i = 0; i < n; ++i) scanf("%s", liz[i]);
    cnt = 0, len = strlen(mp[0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) if (mp[i][j] != '0') {
            id[i][j] = ++cnt;
        }
    }
}

void make_map() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) {
            if (id[i][j]) {
                if (liz[i][j] == 'L') addedge(s, id[i][j], 1), ++ans;
                addedge(id[i][j], id[i][j] + cnt, mp[i][j] - '0');
                for (int a = -k; a <= k; ++a)
                for (int b = -k; b <= k; ++b) {
                    int judge = abs(a) + abs(b);
                    if (judge != 0 && judge <= k) {
                        int x = i + a, y = j + b;
                        if (0 <= x && x < n && 0 <= y && y < len) {
                            addedge(id[i][j] + cnt, id[x][y], INF);
                        }
                        else addedge(id[i][j] + cnt, t, INF);
                    }
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int kk, kase = scanf("%d", &kk); kase <= kk; ++kase) {
        init();
        s = 0, t = cnt * 2 + 1;
        make_map();

        ans -= sap(s, t, cnt * 2 + 2);
        if (ans > 1)
            printf("Case #%d: %d lizards were left behind.\n", kase, ans);
        else if (ans == 1)
            printf("Case #%d: %d lizard was left behind.\n", kase, ans);
        else printf("Case #%d: no lizard was left behind.\n", kase);
    }
    return 0;
}
