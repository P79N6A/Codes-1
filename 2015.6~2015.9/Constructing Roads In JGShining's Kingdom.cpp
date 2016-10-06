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
const int MAXN = 5e5 + 111;
int r[MAXN], x, y, dp[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, kase = 0;
	while (~scanf("%d", &n))
	{
	    memset(dp, 0, sizeof dp);
	    for (int i = 0; i < n; ++i)
	    {
            scanf("%d%d", &x, &y);
            r[x] = y;
        }
        dp[1] = r[1];
        int mx = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (r[i] > dp[mx])
                dp[++mx] = r[i];
            else
            {
                int p = lower_bound(dp, dp + mx, r[i]) - dp;
                dp[p] = r[i];
            }
        }
        printf("Case %d:\n", ++kase);
        if (mx == 1)
            printf("My king, at most %d road can be built.\n\n", mx);
        else
            printf("My king, at most %d roads can be built.\n\n", mx);
    }
	return 0;
}

