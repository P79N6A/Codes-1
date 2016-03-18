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
#include<bitset>
using namespace std;
int mp[20][20], dp[20][1 << 16];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n;
	for (int kase = scanf("%d",&t); kase <= t; ++kase)
	{
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &mp[i][j]);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < (1<<n); ++j)
            {
                int cnt = __builtin_popcount(j);
                if (cnt != i - 1) continue;
                for (int k = 0; k < n; ++k)
                {
                    if (!(j >> k & 1))
                        dp[i][j | (1<<k)] = max(dp[i][j|(1<<k)], dp[i - 1][j] + mp[i][k + 1]);
                }
            }
        printf("Case %d: %d\n", kase, dp[n][(1<<n)-1]);
    }
	return 0;
}
