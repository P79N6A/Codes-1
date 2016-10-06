/*
  对坐标离散化，然后区间标记
  1 10
  1 4
  6 10
  注意上述情况，当离散化时，如果坐标
  相差1以上，应该在他们中间多加一个
  无关坐标，防止离散化后坐标连起来
 */
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
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;

bool have[MAXN];
int x[MAXN], y[MAXN], co[MAXN];
int col[MAXN << 2];

void build(int l, int r, int rt) {
    col[rt] = -1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (l <= mid) build(lson);
    if (mid < r) build(rson);
}

void push_down(int rt) {
    if (col[rt] != -1) {
        col[ls] = col[rt];
        col[rs] = col[rt];
        col[rt] = -1;
    }
}

void update(int L, int R, int l, int r, int rt, int val) {
    if (L <= l && r <= R) {
        col[rt] = val;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, lson, val);
    if (mid < R) update(L, R, rson, val);
}

int query(int l, int r, int rt) {
    if (col[rt] != -1 || l == r) {
        if (col[rt] == -1) return 0;
        if (have[col[rt]]) return 0;
        else {
            have[col[rt]] = 1;
            return 1;
        }
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if (l <= mid) ret += query(lson);
    if (mid < r) ret += query(rson);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d", &m);
        int len = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            co[len++] = x[i], co[len++] = y[i];
        }
        sort(co, co + len);
        len = unique(co, co + len) - co;
        int add = 0;
        for (int i = 1; i < len; ++i) {
            if (co[i] - co[i - 1] > 1) co[len + add++] = co[i - 1] + 1;
        }
        n = len + add;
        sort(co, co + n);
        build(root);
        for (int i = 0; i < m; ++i) {
            x[i] = lower_bound(co, co + n, x[i]) - co;
            y[i] = lower_bound(co, co + n, y[i]) - co;
            update(x[i], y[i], root, i);
        }
        memset(have, 0, sizeof have);
        printf("%d\n", query(root));
    }
    return 0;
}
