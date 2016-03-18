#include<iostream>
#include<cstdio>
#define root 0, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int MAXN = 8e3 + 111;

int color[MAXN << 2], add[MAXN << 2];

void push_up(int rt)
{
    color[rt] = color[rt << 1] | color[rt << 1 | 1];
}

void push_down(int rt, int l, int r)
{
    if (add[rt] != -1)
    {
        add[rt << 1] = add[rt << 1 | 1] = add[rt];
        color[rt << 1] = color[rt << 1 | 1] = 1 << add[rt];
        add[rt] = -1;
    }
}

void build(int l, int r, int rt)
{
    add[rt] = -1;
    if (l == r)
    {
        color[rt] = 1;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return color[rt];
    }
    push_down(rt, l, r);
    int ret = 0;
    int m = l + r >> 1;
    if (L <= m) ret |= query(L, R, lson);
    if (m < R) ret |= query(L, R, rson);
    return ret;
}

void update(int L, int R, int val, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] = val;
        color[rt] = 1 << val;
        return;
    }
    push_down(rt, l, r);
    int m = l + r >> 1;
    if (L <= m) update(L, R, val, lson);
    if (m < R) update(L, R, val, rson);
    push_up(rt);
}

int main()
{
    int n, t, o;
    while (~scanf("%d", &n))
    {
        scanf("%d%d%d", &n, &t, &o);
        build(root);
        char op[2];
        int l, r, col;
        while (o --)
        {
            scanf("%s %d %d", op, &l, &r);
            if (l > r) swap(l, r);
            if (op[0] == 'C')
            {
                scanf("%d", &col);
                update(l, r, col - 1, root);
            }
            else
            {
                printf("%d\n", __builtin_popcount(query(l, r, root)));
            }
        }
    }
    return 0;
}
