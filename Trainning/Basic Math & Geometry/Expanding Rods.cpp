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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
const double eps = 1e-6;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double L, n, c;
    while (scanf("%lf %lf %lf", &L, &n, &c)) {
        if (L < 0 && n < 0 && c < 0) break;
        double l = 0, r = 100 * L;
        double nL = (1 + n * c) * L / 2;
        double ans = -1;
        while (fabs(l - r) > eps) {
            double mid = (l + r) / 2;
            double judge = mid * sin(nL / mid) * 2;
            //pr(judge)
            if (fabs(judge - L) < eps) {
                ans = mid;
                break;
            }
            else if (judge - L < eps) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (ans == -1) {
            printf("0.000\n");
        }
        else printf("%.3f\n", ans - cos(nL / ans) * ans);
    }
    return 0;
}
