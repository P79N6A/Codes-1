#include<cstdio>
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';

const int MAXN = 1e5 + 111;

int sum[MAXN << 2];

void update(int l, int r, int rt, int x, int add) {
    if (l == r) {
        sum[rt] += add;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) update(lson, x, add);
    else update(rson, x, add);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) / 2;
    ll ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    char s[20];
    ll ans = 0, l, r, n = 1e5;
    while (~scanf("%s%d%d", s, &l, &r)) {
        if (s[0] == 'u') {
            update(root, r, l);
        }
        else if (s[0] == 'q') ans += query(l, r, root);
        else update(root, r, -l);
    }
    printf("%lld\n", ans);
    return 0;
}
