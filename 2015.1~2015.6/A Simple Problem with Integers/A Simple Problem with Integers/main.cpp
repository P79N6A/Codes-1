#include <iostream>
#include <cstdio>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
const int MAXN = 1e5 + 11;
typedef long long ll;

ll sum[MAXN << 2], add[MAXN << 2];

void push_dowm(int rt,int m)
{
    if (add[rt])
    {
        add[l(rt)] += add[rt];
        add[r(rt)] += add[rt];
        sum[l(rt)] += add[rt] * (m - (m >> 1));
        sum[r(rt)] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    add[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[l(rt)] + sum[r(rt)];
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    push_dowm(rt, r - l + 1);
    ll ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

void update(int v, int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] += v;
        sum[rt] += (ll)v * (r - l + 1);
        return;
    }
    push_dowm(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(v, L, R, lson);
    if (m < R) update(v, L, R, rson);
    sum[rt] = sum[l(rt)] + sum[r(rt)];
}

int main() {
    int n, q; scanf("%d %d", &n, &q);
    build(root);
    char op[2];
    int l, r, c;
    for (int i = 0; i < q; ++i)
    {
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r, root));
        }
        else {
            scanf("%d %d %d", &l, &r, &c);
            update(c, l, r, root);
        }
    }
    return 0;
}