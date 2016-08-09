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
const int MAXN = 1e5 + 11;

struct Trie {
    int nxt[MAXN][26], id[MAXN], tol, rt;
    int newnode() {
        for (int i = 0; i < 26; ++i) nxt[tol][i] = -1;
        id[tol] = 0;
        return tol++;
    }
    void init() {
        tol = 0;
        rt = newnode();
    }
    void insert(string &s) {
        int len = s.length();
        int cur = rt;
        for (int i = 0; i < len; ++i) {
            int v = s[i] - 'a';
            if (nxt[cur][v] == -1) {
                nxt[cur][v] = newnode();
            }
            cur = nxt[cur][v];
            id[cur] = 0;
        }
    }
}trie;

struct SegT {
    int cnt, ls, rs;
}tree[MAXN * 20];
int root[MAXN], n, tol;
string s[MAXN];

int build(int l, int r) {
    int x = ++tol;
    tree[x].cnt = 0;
    if (l != r) {
        int mid = (l + r) >> 1;
        tree[x].ls = build(l, mid);
        tree[x].rs = build(mid + 1, r);
    }
    return x;
}

void push_up(int rt) {
    int l = tree[rt].ls, r = tree[rt].rs;
    tree[rt].cnt = tree[l].cnt + tree[r].cnt;
}

int update(int l, int r, int rt, int pos, int val) {
    int x = ++tol;
    tree[x] = tree[rt];
    //printf("%d %d\n", l, r);
    if (l == r) {
        tree[x].cnt += val;
        return x;
    }
    int mid = l + r >> 1;
    if (pos <= mid) tree[x].ls = update(l, mid, tree[rt].ls, pos, val);
    else tree[x].rs = update(mid + 1, r, tree[rt].rs, pos, val);
    push_up(x);
    return x;
}

inline void preWork() {
    tol = 0;
    root[0] = build(1, n);
    for (int i = 1; i <= n; ++i) {
        int cur = trie.rt;
        root[i] = root[i - 1];
        for (int j = 0; j < s[i].size(); ++j) {
            int v = s[i][j] - 'a';
            cur = trie.nxt[cur][v];
            if (trie.id[cur]) {
                root[i] = update(1, n, root[i], trie.id[cur], -1);
            }
            trie.id[cur] = i;
        }
        root[i] = update(1, n, root[i], i, s[i].size());
    }
}

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return tree[rt].cnt;
    }
    int mid = l + r >> 1;
    int ret = 0;
    if (L <= mid) ret += query(l, mid, tree[rt].ls, L, R);
    if (mid < R) ret += query(mid + 1, r, tree[rt].rs, L, R);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int q, l, r;
    while (~scanf("%d", &n)) {
        trie.init();
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            trie.insert(s[i]);
        }
        preWork();
        int ans = 0;
        scanf("%d", &q);
        while (q --) {
            scanf("%d%d", &l, &r);
            l = (ans + l) % n + 1, r = (ans + r) % n + 1;
            if (l > r) swap(l, r);
            ans = query(1, n, root[r], l, r);
            printf("%d\n", ans);
        }
    }
    return 0;
}
