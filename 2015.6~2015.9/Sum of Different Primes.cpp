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
const int INF = 0x3f3f3f3f, MAXN = 2111;
int prime[MAXN], len, dp[MAXN][20];
bool is[MAXN];

void init()
{
    for (int i = 2; i< MAXN; ++i)
    {
        if (!is[i])
        {
            prime[len++] = i;
            if (i > 1120) return;
            for (int j = i * i; j < MAXN; j += i)
                is[j] = 1;
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    //cout << len << '\n' << prime[len - 1] << endl;
    int n, k;
    while (cin >> n >> k && (n||k))
    {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < len; ++i)
        {
            for (int j = k; j >= 1; --j)
                for (int p = n; p >= prime[i]; --p)
                    dp[p][j] += dp[p - prime[i]][j - 1];
        }
        cout << dp[n][k] << '\n';
    }
    return 0;
}

