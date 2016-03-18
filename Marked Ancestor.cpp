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

ll p[MAXN];
ll ans;

int find(int x) {
    return p[x] == x ? x : find(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q;
    while (~scanf("%d%d", &n, &q) && (n && q)) {
        p[1] = 1;
        for (int i = 2; i <= n; ++i) {
            scanf("%lld", &p[i]);
        }

        ans = 0;
        int x;
        char op[2];
        while (q --) {
            scanf("%s%d", op, &x);
            if (op[0] == 'Q') {
                ans += find(x);
            }
            else p[x] = x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
