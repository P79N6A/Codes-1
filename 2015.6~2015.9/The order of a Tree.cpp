#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 2e5 + 111;
struct Node{
    int v;
    int l, r;
}node[MAXN];

void build(int u, int v, int e)
{
    if (!node[u].v)
    {
        node[u].v = v;
        return;
    }
    else if(node[u].v > v)
    {
        if (node[u].l) build(node[u].l, v, e);
        else
        {
            node[u].l = e;
            build(node[u].l, v, e);
        }
    }
    else
    {
        if (node[u].r) build(node[u].r, v, e);
        else
        {
            node[u].r = e;
            build(node[u].r, v, e);
        }
    }
}

void dfs(int u)
{
    if (node[u].l)
    {
        printf(" %d", node[node[u].l].v);
        dfs(node[u].l);
    }
    if (node[u].r)
    {
        printf(" %d", node[node[u].r].v);
        dfs(node[u].r);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            node[i].v = node[i].l = node[i].r = 0;
            int x;
            scanf("%d", &x);
            build(0, x, i);
        }
        printf("%d", node[0].v);
        dfs(0);
        puts("");
    }
    return 0;
}
