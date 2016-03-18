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

double base[20];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, w;
    while (scanf("%d%d", &n, &w) && (n | w)) {
        int x = 0;
        double mx = 0;
        int mxv = 0;
        memset(base, 0, sizeof base);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            mxv = max(mxv, x);
            ++base[x / w];
            mx = max(mx, base[x / w]);
        }

        double ans = 0.01;
        double mul = 1.0 / (mxv / w);
        int cnt = 1;
        for (int i = mxv / w - 1; i >= 0; --i) {
            ans += base[i] / mx * cnt * mul;
            ++cnt;
        }

        printf("%.6f\n", ans);
    }
    return 0;
}
