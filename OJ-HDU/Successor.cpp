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
#define root 0, cnt - 1, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN];
int head[MAXN], tol, cnt, lid[MAXN], rid[MAXN], ans[MAXN];
int mx[MAXN << 2];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

map<int, int> who;
struct P {
    int ab, loy, id;
    bool operator < (const P &t) const {
        return ab > t.ab;
    }
}p[MAXN];

inline void init() {
    tol = cnt = 0;
    who.clear();
    who[-1] = -1;
    memset(head, -1, sizeof head);
    memset(mx, -1, sizeof mx);
}

void dfs(int u) {
    lid[u] = cnt++;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        dfs(edge[i].to);
    }
    rid[u] = cnt;
}

int query(int L, int R, int l, int r, int rt) {
    if (L > R) return -1;
    if (L <= l && r <= R) {
        return mx[rt];
    }
    int mid = l + r >> 1;
    int ret = -1;
    if (L <= mid) ret = max(ret, query(L, R, lson));
    if (mid < R) ret = max(ret, query(L, R, rson));
    return ret;
}

void update(int pos, int val, int l, int r, int rt) {
    if (l == r) {
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(pos, val, lson);
    else update(pos, val, rson);
    mx[rt] = max(mx[ls], mx[rs]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1, fa; i < n; ++i) {
            scanf("%d%d%d", &fa, &p[i].loy, &p[i].ab);
            p[i].id = i;
            who[p[i].loy] = i;
            addedge(fa, i);
        }
        dfs(0);
        sort(p + 1, p + n);
        p[0].ab = -1;
        for (int i = 1; i < n; ++i) {
            if (p[i].ab == p[i - 1].ab) continue;
            int j = i;
            while (j < n && p[j].ab == p[i].ab) {
                int id = p[j].id;
                ans[id] = who[query(lid[id] + 1, rid[id] - 1, root)];
                ++j;
            }
            j = i;
            while (j < n && p[j].ab == p[i].ab) {
                int id = p[j].id;
                update(lid[id], p[j].loy, root);
                ++j;
            }
        }
        while (m --) {
            scanf("%d", &n);
            printf("%d\n", ans[n]);
        }
    }
    return 0;
}
