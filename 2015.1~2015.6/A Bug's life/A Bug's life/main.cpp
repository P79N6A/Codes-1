#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 4e3 + 111;

int p[MAXN], ran[MAXN];

void init(int up)
{
    for (int i = 0; i <= up; ++i) p[i] = i, ran[i] = 0;
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
        if (ran[x] == ran[y]) ++ran[x];
    }
}

int main()
{
    int t, n, m, a, b; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        bool flag = 0;
        scanf("%d%d", &n, &m);
        init(2 * n);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) flag = 1;
            else
            {
                unite(a, b + n);
                unite(a + n, b);
            }
        }
        printf("Scenario #%d:\n", kase);
        if (flag) printf("Suspicious bugs found!\n\n");
        else printf("No suspicious bugs found!\n\n");
    }
}