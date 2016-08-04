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
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 211;

struct Seg {
    double l, r, h;
    int add;
    bool operator < (const Seg&t) const {
        return h < t.h;
    }
}a[MAXN];
double co[MAXN];

double sum[MAXN << 3];
int cnt[MAXN << 3];

void push_up(int l, int r, int rt) {
    if (cnt[rt])
        sum[rt] = co[r + 1] - co[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[ls] + sum[rs];
}

void update(int L, int R, int l, int r, int rt, int add) {
    if (L <= l && r <= R) {
        cnt[rt] += add;
        push_up(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, lson, add);
    if (mid < R) update(L, R, rson, add);
    push_up(l, r, rt);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0, n;
    while (~scanf("%d", &n) && n) {
        double x1, y1, x2, y2;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = Seg{x1, x2, y1, 1};
            a[i + n] = Seg{x1, x2, y2, -1};
            co[i] = x1, co[i + n] = x2;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n);
        sort(co + 1, co + 1 + n);
        int len = unique(co + 1, co + 1 + n) - co - 1;
        double ans = 0;
        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
        for (int i = 1; i < n; ++i) {
            int l = lower_bound(co + 1, co + 1 + len, a[i].l) - co;
            int r = lower_bound(co + 1, co + 1 + len, a[i].r) - co;
            // 如果更新l,r那么中间值mid,mid+1这个区间会丢失
            update(l, r - 1, root, a[i].add);
            ans += sum[1] * (a[i + 1].h - a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }
    return 0;
}
