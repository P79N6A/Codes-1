#include <cstdio>
#include <iostream>
using namespace std;
#define INF 0x7f7f7f7f
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int MAXN = 2e5 + 11;

int maxv[MAXN << 2];

void push_up(int rt)
{
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        int x; scanf("%d", &x);
        maxv[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return maxv[rt];
    }
    int m = (l + r) >> 1;
    int ret = -INF;
    if (L <= m) ret = max(ret, query(L, R, lson));
    if (m < R) ret = max(ret, query(L, R, rson));
    return ret;
}

void update(int o, int v, int l, int r, int rt)
{
    if (l == r)
    {
        maxv[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        build(1, n, 1);
        char op[2];
        int l, r;
        for (int i = 0; i < m; ++i)
        {
            scanf("%s %d %d", op, &l, &r);
            if (op[0] == 'Q')
            {
                printf("%d\n", query(l, r, root));
            }
            else update(l, r, root);
        }
    }
    return 0;
}