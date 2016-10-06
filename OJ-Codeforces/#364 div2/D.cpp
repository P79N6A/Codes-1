/*
  想到了最优坐车方法，想到了二分，却没有想到怎么
  使用二分得到的时间。差一个模拟坐车过程的做法= =
  一直在纠结时间和距离之间的关系
  另外二分double不知道该用循环，导致TLE。
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
const int MAXN = 1e6 + 111;
const double eps = 1e-10;

double n, len, v1, v2, k;

bool ok(double T) {
    double st = 0, ed = len;
    int cnt = n;
    while (cnt > k) {
        double t1 = (ed - st - T * v1) / (v2 - v1); // 汽车将人送达最优位置花费的时间
        double t2 = t1 * (v2 - v1) / (v1 + v2);  // 汽车返回的时间
        st += (t1 + t2) * v1;
        T -= (t1 + t2);
        cnt -= k;
    }
    return T * v2 - (ed - st) > -eps; // 最后全部上车，看时间够不够到终点
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%lf%lf%lf%lf%lf", &n, &len, &v1, &v2, &k);
    double ans = -1, l = 0, r = len / v1;
    for (int i = 0; i < 100; ++i) {
        double mid = (r + l) / 2.0;
        if (ok(mid)) {
            ans = mid;
            r = mid;
        }
        else l = mid;
    }
    printf("%.10f\n", ans);
    return 0;
}
