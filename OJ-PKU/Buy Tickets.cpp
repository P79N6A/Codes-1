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
const int MAXN = 2e5 + 111;

int lef[MAXN << 3];
int pos[MAXN], val[MAXN], ans[MAXN];

void build(int l, int r, int rt) {
    lef[rt] = r - l + 1;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    lef[rt] = lef[rt << 1] + lef[rt << 1 | 1];
}

int query(int p, int l, int r, int rt) {
    if (l == r) {
        lef[rt] = 0;
        return l;
    }
    int mid = l + r >> 1;
    int ret = -1;
    if (lef[rt << 1] > p) ret = query(p, lson);
    else ret = query(p - lef[rt << 1], rson);
    lef[rt] = lef[rt << 1] + lef[rt << 1 | 1];
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &pos[i], &val[i]);
        build(root);
        for (int i = n - 1; i >= 0; --i) {
            int p = query(pos[i], root);
            ans[p] = val[i];
        }
        for (int i = 0; i < n; ++i) {
            printf("%d", ans[i]);
            if (i != n - 1) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
