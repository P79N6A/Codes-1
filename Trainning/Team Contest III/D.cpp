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

ll ans[MAXN], tol = 0, n;

// n 变成 2^a*3^b(w)后，w一定是奇数，此时将w拆分成(3^(最大幂次) + 偶数)
// 对于这个偶数，我们又能接着递归处理了
void solve(ll n, ll mul) {
    while (n % 2 == 0) {
        n /= 2;
        mul *= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
        mul *= 3;
    }
    if (n == 1) ans[tol++] = mul;
    else {
        ll x; for (x = 3; x < n; x *= 3);
        x /= 3;
        ans[tol++] = mul * x;
        solve(n - x, mul);
    }
}

int main()
{
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --) {
        tol = 0;
        scanf("%I64d", &n);
        solve(n, 1);
        printf("%I64d\n", tol);
        printf("%I64d", ans[0]);
        for (int i = 1; i < tol; ++i) {
            printf(" %I64d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
