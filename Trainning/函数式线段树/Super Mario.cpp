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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct SegT {
    int ls, rs, sum;
}tree[MAXN * 20];
int tol, root[MAXN * 20];

int a[MAXN], all[MAXN], n, q, len;

inline void preWork() {
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); all[i] = a[i];
    }
    sort(all + 1, all + 1 + n);
    len = unique(all + 1, all + 1 + n) - all - 1;
}

int build(int l, int r) {
    int x = ++tol;
    tree[x].sum = 0;
    if (l == r) return x;
    int mid = (l + r) >> 1;
    tree[x].ls = build(l, mid);
    tree[x].rs = build(mid + 1, r);
    return x;
}

void push_up(int rt) {
    int l = tree[rt].ls, r = tree[rt].rs;
    tree[rt].sum = tree[l].sum + tree[r].sum;
}

int update(int l, int r, int rt, int pos, int val) {
    int x = ++tol;
    tree[x] = tree[rt];
    if (l == pos && r == pos) {
        tree[x].sum += val;
        return x;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) tree[x].ls = update(l, mid, tree[rt].ls, pos, val);
    else tree[x].rs = update(mid + 1, r, tree[rt].rs, pos, val);
    push_up(x);
    return x;
}

int query(int l, int r, int lr, int rr, int L, int R) {
    if (L <= l && r <= R) return tree[rr].sum - tree[lr].sum;
    int mid = (l + r) >> 1;
    int ret = 0;
    if (L <= mid)
        ret += query(l, mid, tree[lr].ls, tree[rr].ls, L, R);
    if (mid < R)
        ret += query(mid + 1, r, tree[lr].rs, tree[rr].rs, L, R);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d%d", &n, &q);
        preWork();
        root[0] = build(1, len);
        for (int i = 1; i <= n; ++i) {
            int pos = lower_bound(all + 1, all + 1 + len, a[i]) - all;
            root[i] = update(1, len, root[i - 1], pos, 1);
        }
        int l, r, h;
        printf("Case %d:\n", kase);
        while (q --) {
            scanf("%d%d%d", &l, &r, &h);
            ++l, ++r;
            int pos = upper_bound(all + 1, all + 1 + len, h) - all - 1;
            if (pos == 0) {
                puts("0");
                continue;
            }
            printf("%d\n", query(1, len, root[l - 1], root[r], 1, pos));
        }
    }
    return 0;
}
