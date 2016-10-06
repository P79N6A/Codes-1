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
const int MAXN = 4e4 + 111;
int coin[3] = {1, 2, 3};
int dp[MAXN];

int main()
{
    int n;
	while (cin >> n)
	{
	    memset(dp, 0, sizeof dp);
	    dp[0] = 1;
	    for (int i = 0; i < 3; ++i)
	    {
	        for (int j = coin[i]; j <= n; ++j)
                dp[j] += dp[j - coin[i]];
        }
        cout << dp[n] << '\n';
	}
	return 0;
}


