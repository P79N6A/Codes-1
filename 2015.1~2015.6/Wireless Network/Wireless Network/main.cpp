#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1110;
int ran[MAXN],par[MAXN];
bool repaired[MAXN];
int mp[MAXN][MAXN];
double d;

struct Computer{
    double x, y;
}c[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        ran[i] = 0; par[i] = i;
    }
}

int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool can(const int a, const int b)
{
    if (mp[a][b] != -1) return mp[a][b];
    return mp[a][b] = mp[b][a] = (c[a].x - c[b].x)*(c[a].x - c[b].x) + (c[a].y - c[b].y)*(c[a].y - c[b].y) <= d * d;
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y])
        par[x] = y;
    else {
        par[y] = x;
        if (ran[x] == ran[y]) ++ran[x];
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    scanf("%d %lf",&n, &d);
    init(n);
    memset(mp, -1, sizeof mp);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf",&c[i].x, &c[i].y);
    char op[2];
    int p, q;
    while (scanf("%s", op) != EOF)
    {
        if (op[0] == 'S')
        {
            scanf("%d %d",&p, &q);
            if (same(p, q))
                printf("SUCCESS\n");
            else printf("FAIL\n");
        }
        else{
            scanf("%d", &p);
            if (!repaired[p])
            {
                repaired[p] = 1;
                for (int i = 1; i <= n; ++i)
                    if (repaired[i] && i != p)
                        if (can(i, p))
                            unite(i,p);
            }
        }
    }
    return 0;
}