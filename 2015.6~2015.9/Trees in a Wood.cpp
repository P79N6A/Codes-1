#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;
ll a, b;

int phi(int x)
{
    int m = (int)sqrt(x + 0.5);
    int ret = x;
    for (int i = 2; i <= m; ++i) if (x % i == 0)
    {
        ret = ret / i * (i - 1);
        while (x%i==0) x /= i;
    }
    if (x > 1) ret = ret / x * (x - 1);
    return ret;
}

int cal(int x)
{
    int base = phi(x);
    int ret = base * (b / x);
    for (int i = b / x * x + 1; i <= b; ++i)
        if (__gcd(i, x) == 1)
            ++ret;
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> a >> b && (a||b))
    {
        double ans = 0;
        for (int i = 1; i <= a; ++i)
            ans += cal(i);
        printf("%.7f\n", (ans * 4 + 4) / (double)(a * b * 4 + a * 2 + b * 2));
    }
    return 0;
}
