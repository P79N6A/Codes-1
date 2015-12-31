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
const int MAXN =  61;

struct Edge{
    int to, next;
    double w;
}edge[MAXN * MAXN];

int head[MAXN], cnt = 0, vis[MAXN], n;
double ANS;

void add_edge(int from, int to, double w)
{
    edge[cnt].to = to;
    edge[cnt].w = w;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}

bool dfs(int target, int cur, int flag, double ans, double dep)
{
    vis[cur] = flag;
    for (int i = head[cur]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == target)
        {
            ANS = min(ANS, (ans + edge[i].w)/ dep);
            return 1;
        }
        if (vis[v] == flag) continue;
        if (dfs(target, v, flag, ans + edge[i].w, dep + 1))
        {
            return 1;
        }
    }
    vis[cur] = flag - 1;
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, m, a, b;
    double c;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d%d", &n, &m);
        cnt = 0;
        memset(head, -1, sizeof head);
        bool fflag;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%lf", &a, &b, &c);
            add_edge(a, b, c);
        }
        ANS = INF;

        int flag = 1;
        for (int i = 1; i <= n; ++i)
        {
            dfs(i, i, flag++, 0, 1);
        }
        printf("Case #%d: ", kase);
        if (ANS == INF) printf("No cycle found.\n");
        else printf("%.2f\n", ANS);
    }
    return 0;
}
