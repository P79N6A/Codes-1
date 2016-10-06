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

int lazy[MAXN << 3];
int sum[MAXN << 3];

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) {
        sum[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update1(int p, int val, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update1(p, val, lson);
    else update1(p, val, rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query1(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if (L <= mid) ret += query1(L, R, lson);
    if (mid < R) ret += query1(L, R, rson);
    return ret;
}

void pushdown(int l, int r, int rt) {
    if (lazy[rt]) {
        sum[rt] += (r - l + 1) * lazy[rt];
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}

void update2(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] += val;
        return;
    }
    pushdown(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update2(L, R, val, lson);
    if (mid < R) update2(L, R, val, rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query2(int p, int l, int r, int rt) {
    pushdown(l, r, rt);
    if (l == r) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    if (p <= mid) return query2(p, lson);
    else return query2(p, rson);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, q; scanf("%d", &t);
    char s[20];
    while (t --) {
        int op, a, b, c;
        scanf("%d", &n);

        scanf("%s %d %d", s, &a, &q);
        build(root);
        while (q --) {
            scanf("%d%d%d", &op, &a, &b);
            if (op) {
                printf("%d\n", query1(a, b, root));
            }
            else {
                update1(a, b, root);
            }
        }

        scanf("%s %d %d", s, &a, &q);
        build(root);
        while (q --) {
            scanf("%d%d", &op, &a);
            if (!op) {
                scanf("%d%d", &b, &c);
                update2(a, b, c, root);
            }
            else {
                printf("%d\n", query2(a, root));
            }
        }
    }
    return 0;
}
