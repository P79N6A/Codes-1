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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct P {
    ll sum[5];
}p[MAXN << 3];
char s[5];
int cnt[MAXN << 3];
int op[MAXN];
int add[MAXN], v[MAXN];

void build(int l, int r, int rt) {
    cnt[rt] = 0;
    memset(p[rt].sum, 0, sizeof p[rt].sum);
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int pos, ll val, int tol, int l, int r, int rt) {
    cnt[rt] += tol;
    if (l == r) {
        p[rt].sum[0] += val * tol;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(pos, val, tol, lson);
    else update(pos, val, tol, rson);
    for (int i = 0; i < 5; ++i) {
        p[rt].sum[i] = p[rt << 1].sum[i] + p[rt << 1 | 1].sum[(i - cnt[rt << 1] % 5 + 5) % 5];
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int num;
    while (~scanf("%d", &num)) {
        int n = 0;
        for (int i = 0; i < num; ++i) {
            scanf("%s", s);
            if (s[0] == 's') op[i] = 0;
            else {
                scanf("%d", &add[n++]);
                v[i] = add[n - 1];
                op[i] = (s[0] == 'a' ? 1 : -1);
            }
        }
        sort(add, add + n);
        n = unique(add, add + n) - add;
        build(root);

        for (int i = 0; i < num; ++i) {
            if (!op[i]) {
                printf("%lld\n", p[1].sum[2]);
            }
            else {
                int pos = lower_bound(add, add + n, v[i]) - add;
                update(pos, add[pos], op[i], root);
            }
        }
    }
    return 0;
}
