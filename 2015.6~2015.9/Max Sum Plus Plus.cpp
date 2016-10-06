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
typedef long long ll;
const int MAXN = 1e6 + 11;
ll a[MAXN], dp[MAXN], mx[MAXN], temx;

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int m, n;
	while (~scanf("%d%d", &m, &n))
	{
	    memset(dp, 0, sizeof dp);
	    memset(mx, 0, sizeof mx);
	    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	    for (int i = 1; i <= m; ++i)
	    {
	        temx = -0x7f7f7f7f;
	        for (int j = i; j <= n; ++j)
	        {
	            dp[j] = max(dp[j - 1] + a[j],mx[j - 1] + a[j]);
	            mx[j - 1] = temx;
	            temx = max(temx, dp[j]);
	        }
	    }
	    printf("%lld\n", temx);
	}
	return 0;
}

