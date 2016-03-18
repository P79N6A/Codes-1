#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 5*1e4 + 50;
int n, k;
int pa[3 * MAXN], ran[3 * MAXN];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
        pa[i] = i, ran[i] = 0;
}

int find(int x)
{
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

void unit(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (ran[x]  < ran[y])
        pa[x] = y;
    else {
        pa[y] = x;
        if (ran[x] == ran[y])
            ++ran[x];
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main() {
    scanf("%d%d",&n, &k);
    init(3 * n);
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        int d, x, y;
        scanf("%d%d%d",&d,&x,&y);
        if (x < 1 || x > n || y < 1 || y > n )
        {
            ++ans;
            continue;
        }
        if (d == 1)
        {
            if (same(x, y + n) || same(x, y + 2 * n)) //x是否不和y同类
                ++ans;
            else{
                unit(x, y);
                unit(x + n, y + n);
                unit(x + 2 * n, y + 2 * n);
            }
        }
        else{
            if (same(x, y) || same(x, y + 2 * n)) //1.x和y同类;2.y吃x
                ++ans;
            else {
                unit(x, y + n);
                unit(x + n, y + 2 * n);
                unit(x + 2 * n, y);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}