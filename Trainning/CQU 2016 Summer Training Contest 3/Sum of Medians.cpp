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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char op[MAXN][4];
int x[MAXN];
int id[MAXN];

struct Seg {
    ll sum[5];
    int num;
}tree[MAXN << 2];

void push_up(int rt) {
    for (int i = 0; i < 5; ++i) {
        int offset = tree[rt << 1].num;
        tree[rt].sum[i] = tree[rt << 1].sum[i] + tree[rt << 1 | 1].sum[(i - offset % 5 + 5) % 5];
    }
}

void update(int l, int r, int rt, int p, int add, int val) {
    tree[rt].num += add;
    if (l == r) {
        tree[rt].sum[0] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(l, mid, rt << 1, p, add, val);
    else update(mid + 1, r, rt << 1 | 1, p, add, val);
    push_up(rt);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, indx = 0; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", op[i]);
        if (op[i][0] != 's') scanf("%d", &x[i]), id[indx++] = x[i];
    }
    sort(id, id + indx);
    indx = unique(id, id + indx) - id;
    for (int i = 0; i < n; ++i) {
        if (op[i][0] == 'a') {
            int pos = lower_bound(id, id + indx, x[i]) - id;
            update(0, n - 1, 1, pos, 1, x[i]);
        }
        else if (op[i][0] == 'd') {
            int pos = lower_bound(id, id + indx, x[i]) - id;
            update(0, n - 1, 1, pos, -1, -x[i]);
        }
        else {
            printf("%I64d\n", tree[1].sum[2]);
        }
    }
    return 0;
}
