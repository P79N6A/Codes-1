#include<algorithm>
#include<bitset>
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
#define root 1, n, 1
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 5;

int mi[MAXN << 2];
ll a[MAXN];

void update(int rt) {
    int ls = mi[rt << 1];
    int rs = mi[rt << 1 | 1];
    if (abs(a[ls]) > abs(a[rs])) {
        mi[rt] = rs;
    }
    else mi[rt] = ls;
}

void build(int l, int r, int rt) {
    if (l == r) {
        mi[rt] = l;
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    update(rt);
}

void update(int l, int r, int rt, int p) {
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) update(lson, p);
    else update(rson, p);
    update(rt);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, x, cnt = 0;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        if (a[i] < 0) ++cnt;
    }
    build(root);
    while (k --) {
        int id = mi[1];
        if (cnt % 2) {
            if (a[id] >= 0) {
                a[id] += x;
            }
            else a[id] -= x;
        }
        else {
            if (a[id] >= 0) {
                a[id] -= x;
                if (a[id] < 0) ++cnt;
            }
            else {
                a[id] += x;
                if (a[id] >= 0) --cnt;
            }
        }
        update(root, id);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%I64d ", a[i]);
    }
    return 0;
}
