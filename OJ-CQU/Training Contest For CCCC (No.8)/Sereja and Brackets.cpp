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
#define root 0, n, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

struct Tree {
    int l, r, lsum, rsum, sum;
    Tree operator + (const Tree &t) {
        Tree ret;
        ret.sum = sum + t.sum + min(lsum, t.rsum);
        ret.lsum = lsum + t.lsum - min(lsum, t.rsum);
        ret.rsum = rsum + t.rsum - min(lsum, t.rsum);
        return ret;
    }
}t[MAXN << 3];

int n;
char s[MAXN];

void push_up(int rt) {
    t[rt].sum = t[ls].sum + t[rs].sum + min(t[ls].lsum, t[rs].rsum);
    t[rt].lsum = t[ls].lsum + t[rs].lsum - min(t[ls].lsum, t[rs].rsum);
    t[rt].rsum = t[ls].rsum + t[rs].rsum - min(t[ls].lsum, t[rs].rsum);
}

void build(int l, int r, int rt) {
    t[rt].l = l, t[rt].r = r;
    t[rt].sum = t[rt].lsum = t[rt].rsum = 0;
    if (l == r) {
        if (s[l] == '(') ++t[rt].lsum;
        else ++t[rt].rsum;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    push_up(rt);
}

Tree query(int L, int R, int rt) {
    int l = t[rt].l, r = t[rt].r;
    if (L <= l && r <= R) {
        return t[rt];
    }
    int mid = l + r >> 1;
    Tree ret1, ret2;
    ret1.sum = -1, ret2.sum = -1;
    if (L <= mid) ret1 = query(L, R, ls);
    if (mid < R) ret2 = query(L, R, rs);
    if (ret1.sum == -1) return ret2;
    if (ret2.sum == -1) return ret1;
    return ret1 + ret2;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%s", s);
    int n = strlen(s) - 1;
    build(root);
    int q, l, r; scanf("%d", &q);
    while (q --) {
        scanf("%d%d", &l, &r);
        --l, --r;
        printf("%d\n", 2 * query(l, r, 1).sum);
    }
    return 0;
}
