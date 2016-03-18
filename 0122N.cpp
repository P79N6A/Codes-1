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
const int MAXN = 1e5 + 111;

long double x[MAXN], y[MAXN], t[MAXN], PI = acos(-1), b = 180, eps = 1e-10;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        t[i] = atan2(y[i], x[i]);
    }

    sort(t, t + n);

    t[n] = t[0] + 2 * acos(-1);
    long double ans = 2 * acos(-1);
    for (int i = 0; i < n; ++i) {
        ans = min(ans, 2 * acos(-1) - fabs(t[i + 1] - t[i]));
    }
    cout << setprecision(10) << ans / PI * 180 << '\n';
    return 0;
}
