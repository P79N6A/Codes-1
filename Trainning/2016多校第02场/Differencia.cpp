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
#define root 0, n - 1, 1
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int MOD = 1e9 + 7;

namespace Storage {
  int data[MAXN << 6], *p;
  void init() {
    p = data;
  }
  int *alloc(int len) {
    p += len;
    return p - len;
  }
}

struct Seg {
    // 该区间第k大，由左子区间贡献了多少，由右子区间贡献了多少
    // 同一子段内，数值相等，所以第几大就代表了有几个比它小的
    int *lindx, *rindx;
    int sum, lazy;
    void setTag(int val) {
        lazy = val;
        sum = val + 1;
    }
    int left(int val) {
        if (~val) return lindx[val];
        else return val;
    }
    int right(int val) {
        if (~val) return rindx[val];
        else return val;
    }
}tree[MAXN << 2];
int a[MAXN], b[MAXN], c[MAXN], save[MAXN];

int A, B, C = ~(1<<31), M = (1<<16)-1;
inline int rnd(int last) {
    A = (36969 + (last >> 3)) * (A & M) + (A >> 16);
    B = (18000 + (last >> 3)) * (B & M) + (B >> 16);
    return (C & ((A << 16) + B)) % 1000000000;
}

inline void update(int rt) {
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
}

inline void push_down(int rt) {
    int &lazy = tree[rt].lazy;
    if (lazy != -2) {
        tree[ls].setTag(tree[rt].left(lazy));
        tree[rs].setTag(tree[rt].right(lazy));
    }
    lazy = -2;
}

void build(int l, int r, int rt) {
    tree[rt].lazy = -2;
    tree[rt].lindx = Storage::alloc(r - l + 1);
    tree[rt].rindx = Storage::alloc(r - l + 1);
    if (l == r) {
        tree[rt].sum = a[l] >= b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    update(rt);
    int sl = mid - l + 1, sr = r - mid;
    int *vl = b + l, *vr = b + mid + 1;
    int i = 0, j = 0, len = 0;
    while (i < sl && j < sr) {
        if (vl[i] < vr[j]) {
            tree[rt].lindx[len] = i;
            tree[rt].rindx[len] = j - 1;
            c[len++] = vl[i++];
        }
        else {
            tree[rt].lindx[len] = i - 1;
            tree[rt].rindx[len] = j;
            c[len++] = vr[j++];
        }
    }
    while (i < sl) {
        tree[rt].lindx[len] = i;
        tree[rt].rindx[len] = j - 1;
        c[len++] = vl[i++];
    }
    while (j < sr) {
        tree[rt].lindx[len] = i - 1;
        tree[rt].rindx[len] = j;
        c[len++] = vr[j++];
    }
    memcpy(b + l, c, sizeof(c[0]) * (r - l + 1));
}

void update(int L, int R, int l, int r, int rt, int val) {
    if (L <= l && r <= R) {
        tree[rt].setTag(val);
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, lson, tree[rt].left(val));
    if (mid < R) update(L, R, rson, tree[rt].right(val));
    update(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return tree[rt].sum;
    }
    push_down(rt);
    int mid = (l + r) >> 1, ret = 0;
    if (L <= mid) ret += query(L, R, lson);
    if (mid < R) ret += query(L, R, rson);
    return ret;
}

bool cmp(int x, int y) {return b[x] < b[y];}

inline void preWork(int n) {
    for (int i = 0; i < n; ++i) c[i] = i;
    sort(c, c + n, cmp);
    for (int i = 0; i < n; ++i) {
        save[i] = b[c[i]];
        b[c[i]] = i;
    }
    for (int i = 0; i < n; ++i)
        a[i] = upper_bound(save, save + n, a[i]) - save - 1;
    Storage::init();
    build(root);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d%d", &n, &m, &A, &B);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        preWork(n);
        int last = 0;
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
             int l = rnd(last) % n + 1;
             int r = rnd(last) % n + 1;
             int x = rnd(last) + 1;
             //printf("%d %d\n", l, r);
             if (l > r) swap(l, r);
             if ((l + r + x) & 1) {
                x = upper_bound(save, save + n, x) - save - 1;
                update(l - 1, r - 1, root, x);
             }
             else {
                last = query(l - 1, r - 1, root);
                //prln(last)
                ans = (ans + (ll)i * last) % MOD;
             }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
