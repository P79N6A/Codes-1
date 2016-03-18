#include<cstdio>

const int MAXN = 5e4 + 111;

int p[3 * MAXN], ran[3 * MAXN];

void init(int up)
{
    for (int i = 0; i <= up; ++i) p[i] = i, ran[i] = 0;
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
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
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    init(3 * n);
    int op, a, b;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d%d", &op, &a, &b);
        if (a < 1 || a > n || b < 1 || b > n) //超出编号范围
        {
            ++ans;
            continue;
        }
        if (op == 1)
        {
            if (same(a, b + n) || same(b, a + n)) //互相存在捕食关系
                ++ans;
            else
            {
                unite(a, b);
                unite(a + n, b + n);
                unite(a + 2*n, b + 2*n);
            }
        }
        else
        {
            if (same(a, b) || same(b, a + n)) //同种；反捕食
                ++ans;
            else
            {
                unite(a, b + n);
                unite(a + n, b + 2*n);
                unite(a + 2*n, b);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}