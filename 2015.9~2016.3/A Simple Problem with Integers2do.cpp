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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

ll sum[MAXN << 2], add[MAXN << 2];

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if (l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void push_down(int l, int r, int rt) {
    if (add[rt] != 0) {
        int m = (l + r) >> 1;
        sum[rt << 1] += (m - l + 1) * add[rt];
        sum[rt << 1 | 1] += (r - m) * add[rt];
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    push_down(l, r, rt);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

void update(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += val;
        sum[rt] += val * (r - l + 1);
        return;
    }
    push_down(l, r, rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, val, lson);
    if (m < R) update(L, R, val, rson);
    push_up(rt);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q, l, r, c;
    char op[2];
    scanf("%d%d", &n, &q);
    build(root);
    while (q --) {
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'Q') printf("%lld\n", query(l, r, root));
        else {
            scanf("%d", &c);
            update(l, r, c, root);
        }
    }
    return 0;
}
