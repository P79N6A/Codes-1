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
const int MAXN = 111;

double save[2] = {2, 2 + sqrt(2)};

double get(double n) {
    if (!n) return 0;
    double ret = 0;
    ret += save[1];
    if (--n == 0) return ret;
    ret += n * 2 * sqrt(2);
    ret += (2 + (2 * n)) * n / 2;
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double m, r;
    scanf("%lf%lf", &m, &r);
    double tol = 0;
    for (int i = 0; i < m; ++i) {
        tol += 2;
        int right = m - 1 - i, left = i;
        tol += get(left) + get(right);
    }
    printf("%.10f\n", tol * r / (m * m));
    return 0;
}
