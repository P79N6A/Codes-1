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
const int MAXN = 2e5 + 111;
const int MOD = 72807249;

ll num[MAXN];
ll a[MAXN << 2];
int n;

ll query(int L, int R, int l, int r, int rt) {
    if (l > r) return 1;
    if (L <= l && r <= R) {
        return a[rt];
    }
    int mid = (l + r) >> 1;
    ll ret = 1;
    if (L <= mid) ret = (ret * query(L, R, lson)) % MOD;
    if (mid < R) ret = (ret * query(L, R, rson)) % MOD;
    return ret;
}

void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
        a[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(p, val, lson);
    else update(p, val, rson);
    a[rt] = (a[rt << 1 | 1] * a[rt << 1]) % MOD;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int t, op; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n * 4; ++i) a[i] = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &op, &num[i]);
            if (op == 1) {
                update(i, num[i], root);
            }
            else {
                update(num[i], 1, root);
            }
            printf("%d\n", a[1]);
        }
    }
    return 0;
}
