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
const int MAXN = 1e4 + 111;
const double eps = 1e-5;

double a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, f;
    double pi = acos(-1);
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &f);
        ++f;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
            a[i] = pi * a[i] * a[i];
        }
        double ans = 0;
        double l = 0, r = 1e9;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += (int)(a[i] / mid);
            }
            if (sum < f) {
                r = mid;
            }
            else {
                ans = mid;
                l = mid;
            }
        }
        printf("%.4f\n", ans);
    }
    return 0;
}
