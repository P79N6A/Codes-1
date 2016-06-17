#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define root 1, n, 1
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

ll sum[MAXN << 3];
struct Lazy {
    ll lval, rval, diff, change, add;
    void init() {
        lval = rval = diff = add = 0;
        change = -1;
    }
}lazy[MAXN << 3];
ll a[MAXN];

void build(int l, int r, int rt) {
    lazy[rt].init();
    if (l == r) {
        sum[rt] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int l, int r, int rt) {
    int mid = l + r >> 1;
    if (lazy[rt].change != -1) {
        sum[rt << 1] = lazy[rt].change * (mid - l + 1);
        sum[rt << 1 | 1] = lazy[rt].change * (r - mid);
        lazy[rt << 1].init();
        lazy[rt << 1 | 1].init();
        lazy[rt << 1].change = lazy[rt << 1 | 1].change = lazy[rt].change;
    }
    if (lazy[rt].diff | lazy[rt].lval | lazy[rt].rval) {
        sum[rt << 1] += (mid - l + 1) * (lazy[rt].lval + lazy[rt].lval + lazy[rt].diff * (mid - l)) / 2;
        sum[rt << 1 | 1] += (r - mid) * (lazy[rt].lval + lazy[rt].diff * (mid - l + 1) + lazy[rt].rval) / 2;
        lazy[rt << 1].lval += lazy[rt].lval;
        lazy[rt << 1].rval += lazy[rt].lval + lazy[rt].diff * (mid - l);
        lazy[rt << 1 | 1].lval += lazy[rt].lval + lazy[rt].diff * (mid - l + 1);
        lazy[rt << 1 | 1].rval += lazy[rt].rval;
        lazy[rt << 1].diff += lazy[rt].diff;
        lazy[rt << 1 | 1].diff += lazy[rt].diff;
    }
    if (lazy[rt].add) {
        sum[rt << 1] += lazy[rt].add * (mid - l + 1);
        sum[rt << 1 | 1] += lazy[rt].add * (r - mid);
        lazy[rt << 1].add += lazy[rt].add;
        lazy[rt << 1 | 1].add += lazy[rt].add;
    }
    lazy[rt].init();
}

void update(int L, int R, int val, int l, int r, int rt) {
    //pr(L)pr(R)pr(val)
    if (L <= l && r <= R) {
        lazy[rt].add += val;
        sum[rt] += val * (r - l + 1);
        //pr(lazy[rt].add)
        return;
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, val, lson);
    if (mid < R) update(L, R, val, rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update2(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        /*pr(val*(l - L + 1))
        pr(l)
        pr(r)
        pr(rt)*/
        lazy[rt].lval += val * (l - L + 1);
        lazy[rt].rval += val * (r - L + 1);
        lazy[rt].diff += val;
        sum[rt] += (r - l + 1) * (val * (l - L + 1) + val * (r - L + 1)) / 2;
        return;
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update2(L, R, val, lson);
    if (mid < R) update2(L, R, val, rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update3(int L, int R, int val, int l, int r, int rt) {
    //pr(l)pr(r)pr(L)pr(R)
    if (L <= l && r <= R) {
        lazy[rt].init();
        lazy[rt].change = val;
        sum[rt] = val * (r - l + 1);
        return;
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update3(L, R, val, lson);
    if (mid < R) update3(L, R, val, rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        /*pr(rt);
        pr(sum[rt]);
        pr(l)pr(r)*/
        return sum[rt];
    }
    push_down(l, r, rt);
    int mid = l + r >> 1;
    ll ret = 0;
    if (L <= mid) ret += query(L, R, lson);
    if (mid < R) ret += query(L, R, rson);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        build(root);

        int op, a, b, c;
        while (m --) {
            scanf("%d%d%d", &op, &a, &b);
            if (op == 4) {
                printf("%lld\n", query(a, b, root));
            }
            else {
                scanf("%d", &c);
                if (op == 1) update(a, b, c, root);
                else if (op == 2) update2(a, b, c, root);
                else  {
                    update3(a, b, c, root);
                    /*for (int i = 1; i <= 30; ++i) {
                        pr(lazy[i].change)
                    }*/
                }
            }
        }
    }
    return 0;
}
