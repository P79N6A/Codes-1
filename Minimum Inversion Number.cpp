#include<iostream>
#include<cstring>
#include<cstdio>
#define lowbit(x) (x & (-x))
#define root 0, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;

const int MAXN = 5e3 + 111;

int sum[MAXN << 2], a[MAXN];

void push_up(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

void update(int x, int l, int r, int rt)
{
    if (l == r)
    {
        ++sum[rt];
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(x, lson);
    else update(x, rson);
    push_up(rt);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(sum, 0, sizeof sum);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ans += query(a[i], n - 1, root);
            update(a[i], root);
        }
        int temp = ans;
        for (int i = 1; i < n; ++i)
        {
            temp += (n - 1 - a[i]) - a[i];
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
