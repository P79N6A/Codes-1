#include <iostream>
#include <cstdio>

const int MAXN = 2e5 + 971;
int par[MAXN], level[MAXN];

void init(const int& n)
{
    for (int i = 0; i < n; ++i)
        par[i] = i, level[i] = 0;
}

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (level[x] < level[y]) par[x] = y;
    else {
        par[y] = x;
        if (level[x] == level[y]) ++level[x];
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main() {
    int t, n, m, a, b;
    scanf("%d",&t);
    while (t --)
    {
        char op[2];
        scanf("%d %d", &n, &m);
        init(2 * n);
        for (int i = 0; i < m; ++i)
        {
            scanf("%s %d %d", op, &a, &b);
            if (op[0] == 'A')
            {
                if (same(a, b))
                    printf("In the same gang.\n");
                else if (same(a, b + n))
                    printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
            else{
                unite(a, b + n);
                unite(a + n, b);
            }
        }
    }
    return 0;
}