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

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};

struct Line
{
    Point v, p;
    Point point(double a){
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

struct Circle{
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) {}
    Point point(double a){
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
{
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
    double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta) < 0) return 0;
    if (dcmp(delta) == 0){
        t1 = t2 = -f / (2 * e); sol.push_back(L.point(t1));
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
    return 2;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        Circle cir;
        Line li;
        double dx, dy;
        scanf("%lf%lf%lf", &cir.c.x, &cir.c.y, &cir.r);
        scanf("%lf%lf%lf%lf", &li.p.x, &li.p.y, &li.v.x, &li.v.y);
        scanf("%lf%lf", &dx, &dy);

    }
    return 0;
}
