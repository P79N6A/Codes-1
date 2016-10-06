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
const int MAXN = 111;
const int MOD = 10000;
int dp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n, m, x; scanf("%d", &t);
	while (t --)
	{
	    scanf("%d%d",&n, &m);
	    memset(dp, 0, sizeof dp);
	    dp[1][1] = 1;
	    for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &x);
                for (int k = i; k <= min(i + x, n); ++k)
                {
                    int lef = x - (k - i);
                    for (int l = j; l <= min(j + lef, m); ++l)
                    {
                        if (k != i || l != j)
                            dp[k][l] = (dp[k][l] + dp[i][j])%MOD;
                    }
                }
            }
        printf("%d\n", dp[n][m]%MOD);
    }
	return 0;
}


