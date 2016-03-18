#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int p[MAXN], ran[MAXN], diff[MAXN], vis[MAXN], n, m, t;

void init()
{
    for (int i = 0; i <= n; ++i)
    {
        p[i] = i;
        ran[i] = 0;
        diff[i] = 0;
        vis[i] = 0;
    }
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (ran[x] > ran[y]) p[y] = x;
    else
    {
        p[x] = y;
        if (ran[x] == ran[y]) ++ran[y];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        init();
        int a, b;
        char c[3];
        for (int i = 0; i < m; ++i)
        {
            scanf("%s %d %d", c, &a, &b);
            if (c[0] == 'A')
            {
                if (!vis[a] || !vis[b])
                    printf("Not sure yet.\n");
                else if (find(a) == find(b))
                    printf("In the same gang.\n");
                else printf("In different gangs.\n");
            }
            else
            {
                vis[a] = vis[b] = 1;
                if (diff[a] == 0) diff[a] = b;
                else unite(diff[a], b);
                if (diff[b] == 0) diff[b] = a;
                else unite(diff[b], a);
            }
        }
    }
    return 0;
}
