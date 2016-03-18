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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 4e4;

int sum[MAXN << 2], lazy[MAXN << 2], n;
string s;

void push_down(int l, int r, int rt) {
    if (lazy[rt] != -1) {
        int m = l + r >> 1;
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        sum[rt << 1] = (m - l + 1) * lazy[rt];
        sum[rt << 1 | 1] = (r - m) * lazy[rt];
        lazy[rt] = -1;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        lazy[rt] = sum[rt] = s[l] - '0';
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];

    if (sum[rt] == r - l + 1)
        lazy[rt] = 1;
    else if (sum[rt] == 0)
        lazy[rt] = 0;
    else
        lazy[rt] = -1;
}

void update(int L, int R, int l, int r, int rt, int flag) {
    if (L <= l && r <= R && !(flag == -1 && lazy[rt] == -1)) {
        if (flag == -1) {
            lazy[rt] = 1 - lazy[rt];
            sum[rt] = (r - l + 1) * lazy[rt];
        }
        else {
            lazy[rt] = flag;
            sum[rt] = (r - l + 1) * lazy[rt];
        }
        return;
    }
    push_down(l, r, rt);
    int m = l + r >> 1;
    if (L <= m) update(L, R, lson, flag);
    if (m < R) update(L, R, rson, flag);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[rt];
    else if (r < L || R < l)
        return 0;

    push_down(l, r, rt);
    int m = l + r >> 1;
    return query(L, R, lson) + query(L, R, rson);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int kase = 1; kase <= t; ++kase) {
        s.clear();
        s += '0';
        int m, time;
        string tmp;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> time >> tmp;
            for (int j = 0; j < time; ++j) {
                s += tmp;
            }
        }
        n = s.length() - 1;

        build(root);

        char op;
        int q, a, b; cin >> q;
        cout << "Case " << kase << ":\n";
        int cnt = 0;
        while (q --) {
            cin >> op >> a >> b;
            ++a, ++b;
            //cout << op << ' ' << a << ' ' << b << endl;
            if (op == 'F') update(a, b, root, 1);
            else if (op == 'E') update(a, b, root, 0);
            else if (op == 'I') update(a, b, root, -1);
            else cout << 'Q' << ++cnt << ": " << query(a, b, root) << '\n';
        }
    }
    return 0;
}
