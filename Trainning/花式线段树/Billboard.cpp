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
const int MAXN = 2e5 + 111;

int mx[MAXN << 2], w;

void build(int l, int r, int rt) {
    mx[rt] = w;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if (l <= mid) build(lson);
    if (mid < r) build(rson);
}

int query(int l, int r, int rt, int val) {
    if (l == r) {
        mx[rt] -= val;
        return l;
    }
    int mid = (l + r) >> 1, ret = -1;
    if (mx[ls] >= val) ret = query(lson, val);
    else if (mx[rs] >= val) ret = query(rson, val);
    mx[rt] = max(mx[ls], mx[rs]);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, num, x;
    while (~scanf("%d%d%d", &n, &w, &num)) {
        n = min(n, num);
        build(root);
        while (num --) {
            scanf("%d", &x);
            if (x > mx[1]) puts("-1");
            else printf("%d\n", query(root, x));
        }
    }
    return 0;
}
