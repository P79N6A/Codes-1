/*
  倒着考虑。那么这个人所要插入的位置，
  就是当前从前往后空着的位置。因为这
  之前如果有人比他靠前，那么就会抢占
  空位，所以按照空位往后数空位的个数
  得到位置进行插入。
 */
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

int ans[MAXN], num[MAXN << 2];
int pos[MAXN], val[MAXN];

void build(int l, int r, int rt) {
    if (l == r) {
        num[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (l <= mid) build(lson);
    if (mid < r) build(rson);
    num[rt] = num[ls] + num[rs];
}

int query(int l, int r, int rt, int val) {
    if (l == r) {
        --num[rt];
        return l;
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if (num[ls] >= val) ret = query(lson, val);
    else ret = query(rson, val - num[ls]);
    num[rt] = num[ls] + num[rs];
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &pos[i], &val[i]);
        }
        build(root);
        for (int i = n - 1; i >= 0; --i) {
            int x = query(root, pos[i] + 1);
            ans[x] = val[i];
        }
        printf("%d", ans[1]);
        for (int i = 2; i <= n; ++i) printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}
