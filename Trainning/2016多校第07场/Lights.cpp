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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 11;
const int MAXM = 5e5 + 11;

struct PT {
    int ls, rs, sum;
}tree[MAXM * 20];
int root[MAXN], tol;

int build(int l, int r) {
    int x = ++tol;
    tree[x].sum = 0;
    if (l != r) {
        int mid = (l + r) >> 1;
        tree[x].ls = build(l, mid);
        tree[x].rs = build(mid + 1, r);
    }
    return x;
}

int update(int l, int r, int rt, int p, int val) {
    int x = ++tol;
    tree[x] = tree[rt];
    if (l == r) {
        tree[x].sum += val;
        return x;
    }
    int mid = l + r >> 1;
    if (p <= mid) tree[x].ls = update(l, mid, tree[rt].ls, p, val);
    else tree[x].rs = update(mid + 1, r, tree[rt].rs, p, val);

    int lsn = tree[x].ls, rsn = tree[x].rs;
    tree[x].sum = tree[lsn].sum + tree[rsn].sum;
    return x;
}

int query(int l, int r, int L, int R, int rt) {
    if (L <= l && r <= R) {
        return tree[rt].sum;
    }
    int mid = l + r >> 1;
    int ret = 0;
    if (L <= mid) ret += query(l, mid, L, R, tree[rt].ls);
    if (mid < R) ret += query(mid + 1, r, L, R, tree[rt].rs);
    return ret;
}

// match记录平行的最左边对应的tree
int mx, n, match[MAXN];
vector<int> G[MAXN];

bool ok() {
    tol = 0;
    root[0] = build(1, mx);
    memset(match, 0, sizeof match);
    for (int i = 1; i <= 5e4; ++i) {
        root[i] = root[i - 1];
        for (int j = 0; j < G[i].size(); ++j) {
            int l = j == 0 ? 0 : G[i][j - 1];
            int r = j == G[i].size() - 1 ? mx + 1 : G[i][j + 1];
            int ans1 = query(1, mx, l + 1, r - 1, root[match[G[i][j]]]);
            int ans2 = query(1, mx, l + 1, r - 1, root[i]);
//            pr(l)pr(r)
//            printf("%d %d\n", ans1, ans2);
            if (ans1 != ans2) return 0;
        }
        for (int j = 0; j < G[i].size(); ++j) {
            root[i] = update(1, mx, root[i], G[i][j], 1);
            match[G[i][j]] = i;
        }
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x, y;
    while (~scanf("%d", &n) && n) {
        mx = 0;
        for (int i = 0; i < MAXN; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            mx = max(mx, y);
            G[x].push_back(y);
        }
        for (int i = 1; i < MAXN; ++i) {
            sort(G[i].begin(), G[i].end());
            G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
        }
        puts(ok() ? "YES" : "NO");
    }
    return 0;
}
