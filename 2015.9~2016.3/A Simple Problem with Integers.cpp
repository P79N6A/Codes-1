#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int MAXN = 1e5 + 111;

ll sum[MAXN << 2], add[MAXN << 2];

void push_up(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
    add[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void push_down(int rt, int l, int r)
{
    if (add[rt] != 0)
    {
        int m = l + r >> 1;
        sum[rt << 1] += (m - l + 1) * add[rt];
        sum[rt << 1 | 1] += (r - m) * add[rt];
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    push_down(rt, l, r);
    ll ret = 0;
    int m = l + r >> 1;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

void update(int L, int R, int val, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        sum[rt] += (r - l + 1) * val;
        add[rt] += val;
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
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q;
    scanf("%d%d", &n, &q);
    {
        build(root);
        char op[2];
        int l, r, x;
        while (q --)
        {
            scanf("%s %d %d", op, &l, &r);
            if (op[0] == 'Q') printf("%lld\n", query(l, r, root));
            else
            {
                scanf("%d", &x);
                update(l, r, x, root);
            }
        }
    }
    return 0;
}
