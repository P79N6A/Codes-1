#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

const double eps = 1e-6;
const double PI = acos(-1);

bool judge(double p, double x, double y) {
    if (x * x + y * y - 50 * 50 > eps) return true;
    double x1 = 0, y1 = 50;
    double x2 = x - 50, y2 = y - 50;
    double cs = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    double cur = acos(cs);
    if (y < 50) cur = 2 * PI - cur;
    p = 2 * PI * p / 100;
    return cur > p + eps;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t; cin >> t;
    double p, x, y;
    for (int kase = 1; kase <= t; ++kase) {
        cin >> p >> x >> y;
        bool flag = judge(p, x, y);
        cout << "Case #" << kase << ": " << (flag? "white" : "black") << '\n';
    }
    return 0;
}