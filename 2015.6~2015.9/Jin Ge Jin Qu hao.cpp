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
const int MAXN = 1e4 + 666;
int dp[MAXN];
int num[MAXN];
int minu[60];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n, time; cin >> t;
	for(int kase = 1; kase <= t; ++kase)
	{
	    cin >> n >> time;
	    for(int i = 0; i < n; ++i) cin >> minu[i];
	    memset(dp, -0x3f, sizeof dp);
	    --time;
	    int ans = 0;
	    dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = time; j >= minu[i]; --j)
            {
                dp[j] = max(dp[j - minu[i]] + 1, dp[j]);
                ans = max(dp[j], ans);
            }
        }
        int cnt = 0;
        for(int i = 0; i <= time; ++i)
        {
            if(dp[i] == ans)
            {
                cnt = i;
            }
        }
        cout << "Case " << kase << ": " << ans + 1 << ' ' << cnt + 678 << '\n';
    }
	return 0;
}


