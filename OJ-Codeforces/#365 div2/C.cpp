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
const int MAXN = 1e4 + 111;
const double eps = 1e-10;

struct Point {
    double x, y;
    bool operator < (const Point&rhs) const {
        if (y == rhs.y) return x < rhs.x;
        return y < rhs.y;
    }
}p[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    double w, v, u;
    cin >> n >> w >> v >> u;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n);
    bool go = 1;
    for (int i = 0; i < n; ++i) {
        double time = p[i].x / v;
        double len = time * u;
        if (len < p[i].y - eps) {
            go = 0;
            break;
        }
    }
    if (go) {
        printf("%.10f\n", w / u);
        return 0;
    }
    double y = 0, time = 0;
    for (int i = 0; i < n; ++i) {
        double t = p[i].x / v;
        if (t < time - eps) continue;
        double ny = (t - time) * u + y;
        if (ny > p[i].y - eps) {
            y = p[i].y;
        }
        else {
            y = ny;
        }
        time = t;
    }
    printf("%.10f\n", (w - y) / u + time);
    return 0;
}
