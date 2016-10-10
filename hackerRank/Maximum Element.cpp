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
#define ll long long
#define root 1, n, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int st[MAXN], l, r;
int mx[MAXN << 3];

void update(int l, int r, int rt, int p, int val) {
    if (l == r) {
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) update(lson, p, val);
    else update(rson, p, val);
    mx[rt] = max(mx[ls], mx[rs]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, op, x; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            ++r;
            update(root, r, x);
        }
        else if (op == 2) {
            update(root, r, 0);
            --r;
        }
        else {
            printf("%d\n", mx[1]);
        }
    }
    return 0;
}
