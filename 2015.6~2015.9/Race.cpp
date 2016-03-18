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
const int INF = 0x7f7f7f7f, MAXN = 1111, MOD =  10056;
int n, c[MAXN][MAXN], f[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    for (int i = 0; i <= 1000; ++i) c[i][0] = 1;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= i; ++j)
        {
            if (i - 1 >= j)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%MOD;
            else c[i][j] = 1;
        }
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= 1000; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            f[i] += c[i][j] * f[i - j] % MOD;
        }
        f[i] %= MOD;
    }
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", kase, f[n]);
    }
    return 0;
}

