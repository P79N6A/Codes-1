#include<cstdio>
#include<iostream>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int sum[MAXN << 2], lsum[MAXN << 2], rsum[MAXN << 2], a[MAXN], n, q;

void build(int l, int r, int rt)
{
    sum[rt] = lsum[rt] = rsum[rt] = 1;
    if (l == r)
    {
        scanf("%d", &a[l]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    // 向上更新信息
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
    if (a[m] == a[m + 1]) // 左子区间的从右往左连续段 + 右子区间从左往右连续段
        sum[rt] = max(sum[rt], rsum[rt << 1] + lsum[rt << 1 | 1]);
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    if (a[m] == a[m + 1])
    {
        if (lsum[rt] == m - l + 1)
            lsum[rt] += lsum[rt << 1 | 1];
        if (rsum[rt] == r - m)
            rsum[rt] += rsum[rt << 1];
    }
}

int query(int L, int R, int l, int r, int rt)
{
    if (L == l && r == R) // 区间相等时才直接返回sum[]
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    if (m < L) return query(L, R, rson);
    else if (R <= m) return query(L, R, lson);
    else
    {
        int ret = max(query(L, m, lson), query(m + 1, R, rson));
        if (a[m] == a[m + 1])
        {
            int lans = min(m - L + 1, rsum[rt << 1]); // 注意两者取小
            int rans = min(R - m, lsum[rt << 1 | 1]);
            ret = max(ret, lans + rans);
        }
        return ret;
    }
}

int main()
{
    while (~scanf("%d", &n) && n)
    {
        scanf("%d", &q);
        build(root);
        int l, r;
        for (int i = 0; i < q; ++i)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", query(l, r, root));
        }
    }
    return 0;
}
