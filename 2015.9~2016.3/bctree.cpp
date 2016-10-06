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
const int MAXN = 1e5 + 111;

int pa[MAXN], rnk[MAXN], ans[MAXN];

int find(int x)
{
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] > rnk[y]) {
            pa[y] = x;
            ans[x] += ans[y];
        }
        else {
            pa[x] = y;
            ans[y] += ans[x];
            if (rnk[x] == rnk[y]) ++rnk[y];
        }
    }
    return;
}

int main()
{
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            pa[i] = i; rnk[i] = 0; ans[i] = 1;
        }
        int a, b, c;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            if (c == 0) {
                unite(a, b);
            }
        }
        int anss = 0;
        for (int i = 1; i <= n; ++i) {
            int x = find(i);
            anss ^= ans[x];
        }
        printf("%d\n", anss);
    }
    return 0;
}
