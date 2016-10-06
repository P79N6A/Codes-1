/*
  µã¶¯
 */
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 41;
const double PI = acos(-1);
const double eps = 1e-10;

int n;
double x[MAXN], y[MAXN];

double solve(double deg) {
    double mix = 1000, mxx = -1000;
    double miy = 1000, mxy = -1000;
    for (int i = 0; i < n; ++i) {
        double nx = x[i] * sin(deg) + y[i] * cos(deg);
        double ny = x[i] * cos(deg) - y[i] * sin(deg);
        mix = min(mix, nx), mxx = max(mxx, nx);
        miy = min(miy, ny), mxy = max(mxy, ny);
    }
    return max(mxx - mix, mxy - miy);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lf%lf", &x[i], &y[i]);
        double l = 0, r = 2 * PI;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            double mmid = (mid + r) / 2;
            if (solve(mid) < solve(mmid)) r = mmid;
            else l = mid;
        }
        double ans = solve(l);
        printf("%.2f\n", ans * ans);
    }
    return 0;
}
