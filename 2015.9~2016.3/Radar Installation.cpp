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
const int MAXN = 1e3 + 111;

struct Island {
    double x, y;
    bool operator < (const Island &t)const {
        if (x == t.x) return y > t.y;
        return x < t.x;
    }
}island[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, kase = 0;
    double d;
    while (~scanf("%d%lf", &n, &d) && (n || d)) {
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &island[i].x, &island[i].y);
        sort(island, island + n);

        int cnt = 0;
        double pos = -INF;

        for (int i = 0; i < n; ++i) {
            if (d < island[i].y) {
                cnt = -1;
                break;
            }
            double templ = island[i].x - sqrt(d * d - island[i].y * island[i].y);
            double tempr = island[i].x + sqrt(d * d - island[i].y * island[i].y);
            if (templ <= pos && pos <= tempr) continue;
            else if (pos > tempr) pos = tempr;
            else {
                ++cnt;
                pos = tempr;
            }
        }

        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}
