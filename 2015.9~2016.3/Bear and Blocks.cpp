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

int h[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        h[1] = h[n] = 1;
        for (int i = 2; i <= n; ++i) {
            h[i] = min(h[i - 1] + 1, h[i]);
        }
        for (int i = n - 1; i >= 1; --i) {
            h[i] = min(h[i + 1] + 1, h[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = max(ans, h[i]);
        printf("%d\n", ans);
    }
    return 0;
}
