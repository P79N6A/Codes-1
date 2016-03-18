#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 2e3 + 111, MOD = 100000007;
bool mp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n, m, k, x, y;
    while (~scanf("%I64d%I64d%I64d", &n, &m, &k))
    {
        ll a = ceil((double)n / 2);
        ll total = a * (a + 1) / 2;
        memset(mp, 0, sizeof mp);
        for (int i = 0; i < m; ++i)
        {
            scanf("%I64d %I64d", &x, &y);
            ++x, ++y;
            if (2 * x > n) x = n - x + 1;
            if (2 * y > n) y = n - y + 1;
            if (!mp[x][y]) mp[x][y] = mp[y][x] = 1, --total;
        }
        ll ans = 1;
        while (total > 0)
        {
            if (total & 1) ans = (ans * k) % MOD;
            total >>= 1;
            k *= k;
            k %= MOD;
        }
        printf("%I64d\n", ans % MOD);
    }
    return 0;
}

