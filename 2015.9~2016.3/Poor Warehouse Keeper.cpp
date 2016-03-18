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
const double eps = 1e-5;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double x, y;
    while (~scanf("%lf%lf", &x, &y)) {
        if (x > y) {
            printf("-1\n");
            continue;
        }

        double mx = (y + 1 - eps) / x;
        double cur = 1;
        int ans = (int)x - 1;
        for (int i = 1; i <= (int)x; ++i) {
            double target = i * mx;
            int add = (int)(target - cur);
            cur += add;
            ans += add;
            cur = cur * (i + 1) / i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
