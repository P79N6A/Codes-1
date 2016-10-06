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
const int MAXN = 1e6 + 111;

int p[MAXN], rnk[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rnk[x] > rnk[y]) p[y] = p[x];
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
    int t, n, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 2 * n; ++i) p[i] = i, rnk[i] = 0;
        char op[2];
        int a, b;
        while (m --) {
            scanf("%s%d%d", &op, &a, &b);
            if (op[0] == 'A'){
                if (find(a) == find(b) || find(a + n) == find(b + n)) printf("In the same gang.\n");
                else if (find(a) == find(b + n) || find(b) == find(b + n)) printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
            else {
                unite(a, b + n);
                unite(a + n, b);
            }
        }
    }
    return 0;
}
