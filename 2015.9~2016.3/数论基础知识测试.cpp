#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

void extgcd(int a, int b, int &x, int &y)
{
    if (b != 0)
    {
        extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1; y = 0;
    }
}

int euler(int x)
{
    int ret = x, t = x;
    for (int i = 2; i * i <= x; ++i)
    {
        if (t % i == 0)
        {
            ret = ret / i * (i - 1);
            while (t % i == 0) t /= i;
        }
    }
    if (t > 1) ret = ret / t * (t - 1);
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int op, a, b, n, ans;
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i)
            {
                scanf("%d", &a);
                if (i == 0) ans = a;
                else ans = __gcd(ans, a);
            }
        }
        else if (op == 2)
        {
            scanf("%d%d", &a, &b);
            int x, y;
            extgcd(a, b, x, y);
            ans = (b + x % b)%b; // 防止负数取模
        }
        else
        {
            scanf("%d", &a);
            ans = euler(a);
        }
        printf("%d\n", ans);
    }
    return 0;
}
