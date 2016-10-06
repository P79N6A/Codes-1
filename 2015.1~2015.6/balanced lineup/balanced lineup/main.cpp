#include <cstdio>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int N = 5e4 + 111;

int sum[N << 2], maxv[N << 2], minv[N << 2], add[N << 2];

void push_up(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void push_down(int rt, int m)
{
    if (add[rt]){
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        int x; scanf("%d", &x);
        sum[rt] = maxv[rt] = minv[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

//op:查询操作 0求和 1最大 2最小  [L,R]查询区间
int query(int op, int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        if (op == 0)
            return sum[rt];
        if (op == 1)
            return maxv[rt];
        if (op == 2)
            return minv[rt];
    }
    int m = (l + r) >> 1;
    push_down(rt, r - l + 1);
    if (op == 0)
    {
        int ret = 0;
        if (L <= m) ret += query(op, L, R, lson);
        if (m < R) ret += query(op, L, R, rson);
        return ret;
    }
    else if (op == 1)
    {
        int ret = -INF;
        if (L <= m) ret = max(ret, query(op, L, R, lson));
        if (m < R) ret = max(ret,query(op, L, R, rson));
        return ret;
    }
    else{
        int ret = INF;
        if (L <= m) ret = min(ret, query(op, L, R, lson));
        if (m < R) ret = min(ret,query(op, L, R, rson));
        return ret;
    }
}

void update(int o, int v, int l, int r, int rt)//需要到的点
{
    if (l == r)
    {
        sum[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2)
    {
        build(root);
        while (q --)
        {
            int l, r; scanf("%d%d", &l, &r);
            int Max = query(1, l, r, root);
            int Min = query(2, l, r, root);
            printf("%d\n", Max - Min);
        }
    }
    return 0;
}