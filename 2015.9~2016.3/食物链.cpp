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
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5;

int p[MAXN], rnk[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rnk[x] > rnk[y]) {
        p[y] = p[x];
    }
    else {
        p[x] = p[y];
        if (rnk[x] == rnk[y]) ++rnk[y];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < 3 * n; ++i) p[i] = i, rnk[i] = 0;

    int op, x, y, ans = 0;
    while (k --) {
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || x < 1 || y > n || y < 1) {
            ++ans; continue;
        }
        --x, --y;
        if (op == 1) {
            if (find(x) == find(y + n) || find(y) == find(x + n)) ++ans;
            else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        }
        else {
            if (find(x) == find(y) || find(y) == find(x + n)) ++ans;
            else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
