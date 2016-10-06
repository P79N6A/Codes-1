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
const int MAXN = 6;
const double eps = 1e-10;

double x[MAXN], y[MAXN], p, q, r, ab, cd;

double getdis(int a, int b) {
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx * dx + dy * dy);
}

double need(double time) {
    x[5] = x[3] + (x[2] - x[3]) * time / (cd / q);
    y[5] = y[3] + (y[2] - y[3]) * time / (cd / q);
    return getdis(4, 5) / r + time;
}

double solve(double time) {
    x[4] = x[0] + (x[1] - x[0]) * time / (ab / p);
    y[4] = y[0] + (y[1] - y[0]) * time / (ab / p);
    double l = 0, r = cd / q;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        double mmid = (mid + r) / 2;
        if (need(mid) < need(mmid)) r = mmid;
        else l = mid;
    }
    return time + need(l);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        for (int i = 0; i < 4; ++i) scanf("%lf%lf", &x[i], &y[i]);
        scanf("%lf%lf%lf", &p, &q, &r);
        ab = getdis(0, 1);
        cd = getdis(2, 3);
        double l = 0, r = ab / p;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            double mmid = (mid + r) / 2;
            if (solve(mid) < solve(mmid)) r = mmid;
            else l = mid;
        }
        printf("%.2f\n", solve(l));
    }
    return 0;
}
