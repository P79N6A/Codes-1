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
const int MAXN = 1e6 + 111;

double a[60];

bool cmp(double a, double b) {
    return a > b;
}

int main()
{
    int n, t; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n, cmp);
        double ans = 0, base = 1;
        for (int i = 0; i < n; ++i) {
            ans += base * a[i];
            base *= 0.95;
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
