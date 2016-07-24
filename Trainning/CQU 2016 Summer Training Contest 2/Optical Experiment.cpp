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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int a[MAXN];
//int l[MAXN], r[MAXN];
//int mx[MAXN << 3];
struct P {
    int id, num;
    bool operator < (const P&t)const {
        return num < t.num;
    }
}p[MAXN];

int n;

//void build(int l, int r, int rt) {
//    mx[rt] = 0;
//    if (l == r) {
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(lson);
//    build(rson);
//}
//
//void update(int p, int l, int r, int rt, int val) {
//    if (l == r) {
//        mx[rt] = val;
//        return;
//    }
//    int mid = (l + r) >> 1;
//    if (mid >= p) update(p, lson, val);
//    else update(p, rson, val);
//    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
//}
//
//int query(int L, int R, int l, int r, int rt) {
//    if (L <= l && r <= R) {
//        return mx[rt];
//    }
//    int mid = (l + r) >> 1;
//    int ret = 0;
//    if (L <= mid) ret = max(ret, query(L, R, lson));
//    else ret = max(ret, query(L, R, rson));
//    return ret;
//}

int dp[MAXN];
int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i].num), p[i].id = i;
    sort(p, p + n);
    P temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        temp.num = a[i];
        int pos = lower_bound(p, p + n, temp) - p;
        a[i] = -p[pos].id;
    }
    memset(dp, 0x3f, sizeof dp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(dp, dp + ans, a[i]) - dp;
        dp[x] = a[i];
        ans = max(ans, x + 1);
    }
    printf("%d\n", ans);
    return 0;
}
