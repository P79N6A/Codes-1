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
const int MAXN = 5e4 + 111;

int sum[MAXN], a[MAXN << 2], add[MAXN << 2];
char s[MAXN];

void build(int l, int r, int rt) {
    add[rt] = 0;
    if (l == r) {
        a[rt] = sum[l];
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    return;
}

void push_down(int rt) {
    if (add[rt] != 0) {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        return;
    }
    push_down(rt);
    int m = l + r >> 1;
    if (L <= m) update(L, R, x, lson);
    if (m < R) update(L, R, x, rson);
    return;
}

int query(int x, int l, int r, int rt) {
    if (l == r) {
        return a[rt] + add[rt];
    }
    push_down(rt);
    int m = l + r >> 1;
    if (m < x) return query(x, rson);
    else return query(x, lson);
}

int main()
{
    int m, t, n;
    for (int kase = scanf("%d", &t); kase <= t; ++kase) {
        printf("Case %d:\n", kase);
        scanf("%d%d%s", &n, &m, s + 1);
        sum[0] = sum[1] = sum[2] = 0;
        for (int i = 3; i <= n; ++i) {
            sum[i] = sum[i - 1];
            if (s[i] == 'w' && s[i - 1] == 'b' && s[i - 2] == 'w')
                ++sum[i];
        }
        build(root);
        int op, l, r;
        char x[2];
        while (m --) {
            scanf("%d%d", &op, &l);
            if (op == 0) {
                scanf("%d", &r);
                ++l, ++r;
                if (r - l + 1 < 3) printf("0\n");
                else
                    printf("%d\n", query(r, root) - query(l + 1, root));
            }
            else {
                scanf("%s", x);
                ++l;
                if (s[l] != x[0]) {
                    if (l >= 3 && s[l] == 'w' && s[l - 1] == 'b' && s[l - 2] == 'w')
                        update(l, n, -1, root);

                    if (l >= 2 && l + 1 <= n && s[l] == 'b' && s[l - 1] == 'w' && s[l + 1] == 'w')
                        update(l + 1, n, -1, root);

                    if (l + 2 <= n && s[l] == 'w' && s[l + 1] == 'b' && s[l + 2] == 'w')
                        update(l + 2, n, -1, root);

                    s[l] = x[0];

                    if (l >= 3 && s[l] == 'w' && s[l - 1] == 'b' && s[l - 2] == 'w')
                        update(l, n, 1, root);

                    if (l >= 2 && l + 1 <= n && s[l] == 'b' && s[l - 1] == 'w' && s[l + 1] == 'w')
                        update(l + 1, n, 1, root);

                    if (l + 2 <= n && s[l] == 'w' && s[l + 1] == 'b' && s[l + 2] == 'w')
                        update(l + 2, n, 1, root);
                }
            }
        }
    }
    return 0;
}
