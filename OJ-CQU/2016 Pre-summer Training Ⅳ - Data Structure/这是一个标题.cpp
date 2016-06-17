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
#define ls rt << 1
#define rs rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int a[MAXN];
ll sum[MAXN << 3], mx[MAXN << 3], lmx[MAXN << 3], rmx[MAXN << 3];
int cnt = 0;

void push_up(int rt) {
    sum[rt] = sum[ls] + sum[rs];
    lmx[rt] = max(lmx[ls], lmx[rs] + sum[ls]);
    rmx[rt] = max(rmx[rs], rmx[ls] + sum[rs]);
    mx[rt] = max(rmx[ls] + lmx[rs], max(mx[ls], mx[rs]));
    mx[rt] = max(mx[rt], max(lmx[rt], rmx[rt]));
}

void build(int l, int r, int rt) {
    if (l == r) {
        sum[rt] = mx[rt] = lmx[rt] = rmx[rt] = a[l];
        cnt = max(cnt, rt);
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L == l && r == R) {
        return rt;
    }
    int mid = l + r >> 1;
    if (mid < L) return query(L, R, rson);
    else if (R <= mid) return query(L, R, lson);
    else {
        int x = query(L, mid, lson);
        int y = query(mid + 1, R, rson);
        ++cnt;
        sum[cnt] = sum[x] + sum[y];
        lmx[cnt] = max(lmx[x], lmx[y] + sum[x]);
        rmx[cnt] = max(rmx[y], rmx[x] + sum[y]);
        mx[cnt] = max(rmx[x] + lmx[y], max(mx[x], mx[y]));
        mx[cnt] = max(mx[cnt], max(lmx[cnt], rmx[cnt]));
        return cnt;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        cnt = 0;
        build(root);
        int l, r;
        int save = cnt;
        while (m --) {
            scanf("%d%d", &l, &r);
            cnt = save;
            int x = query(l, r, root);
            printf("%lld\n", mx[x]);
        }
    }
    return 0;
}
