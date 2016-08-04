/*
  主席树究竟是一棵什么样的树呢？
  应该说是一个森林，里面放着新增结点之后的线段树
  root[0]代表啥都没放，root[1]代表放了结点1之后的样子
  新线段树比起旧线段树，只更改了旧线段树中的个别区间，
  所以我们只需要给个别区间重新编号就行了。
  然后像本题查询区间第k大，我们就能用历史线段树的历史区间来查询我们需要的结果。
  看query函数就知道了，实际上我们查询是在两棵树上做查询，
  sum保存的是这个区间中有多少个数
  两树相减代表这区间在历史(l - 1)到(r)之间添加了多少数
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct SegT {
    int ls, rs, sum;
}tree[MAXN * 20];
int tol, root[MAXN * 20];

int a[MAXN], all[MAXN], n, q, len;

inline void preWork() {
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); all[i] = a[i];
    }
    sort(all + 1, all + 1 + n);
    len = unique(all + 1, all + 1 + n) - all - 1;
}

int build(int l, int r) {
    int x = ++tol;
    tree[x].sum = 0;
    if (l == r) return x;
    int mid = (l + r) >> 1;
    tree[x].ls = build(l, mid);
    tree[x].rs = build(mid + 1, r);
    return x;
}

int update(int l, int r, int rt, int pos, int val) {
    int x = ++tol;
    tree[x] = tree[rt];
    tree[x].sum += val;
    if (l == pos && r == pos) return x;
    int mid = (l + r) >> 1;
    if (pos <= mid) tree[x].ls = update(l, mid, tree[rt].ls, pos, val);
    else tree[x].rs = update(mid + 1, r, tree[rt].rs, pos, val);
    return x;
}

int query(int l, int r, int lr, int rr, int k) {
    if (l == r) return l;
    int res = tree[tree[rr].ls].sum - tree[tree[lr].ls].sum;
    int mid = (l + r) >> 1;
    if (k <= res)
        return query(l, mid, tree[lr].ls, tree[rr].ls, k);
    else
        return query(mid + 1, r, tree[lr].rs, tree[rr].rs, k - res);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &q)) {
        preWork();
        root[0] = build(1, len);
        for (int i = 1; i <= n; ++i) {
            int pos = lower_bound(all + 1, all + 1 + len, a[i]) - all;
            root[i] = update(1, len, root[i - 1], pos, 1);
        }
        int l, r, k;
        while (q --) {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", all[query(1, len, root[l - 1], root[r], k)]);
        }
    }
    return 0;
}
