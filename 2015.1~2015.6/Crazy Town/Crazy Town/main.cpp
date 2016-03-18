#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

const double eps = 1e-7;

int main() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        double a, b, c;
        cin >> a >> b >> c;
        if ((a * x1 + b * y1 + c)*(a * x2 + b * y2 + c) < eps) //线性规划：当两点在直线两端时，带入两点，乘积必定是负数
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}
