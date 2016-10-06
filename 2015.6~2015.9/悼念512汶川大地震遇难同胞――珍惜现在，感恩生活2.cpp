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
int dp[MAXN], a[MAXN], b[MAXN], c[MAXN];

int main()
{
	int t, n, m; cin >> t;
	while (t --)
	{
	    cin >> n >> m;
	    memset(dp, 0, sizeof dp);
	    for (int i = 0; i < m; ++i) cin >> a[i] >> b[i] >> c[i];
	    for (int i = 0; i < m; ++i)
	    {
            if (a[i] * c[i] >= n)
            {
                for (int j = a[i]; j <= n; ++j)
                    dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
            else
            {
                int k = 1;
                while (k < c[i])
                {
                    for (int j = n; j >= k * a[i]; --j)
                        dp[j] = max(dp[j], dp[j - k*a[i]] + k*b[i]);
                    c[i] -= k;
                    k *= 2;
                }
                for (int j = n; j >= c[i] * a[i]; --j)
                    dp[j] = max(dp[j], dp[j - c[i]*a[i]] + c[i]*b[i]);
            }
	    }
	    cout << dp[n] << '\n';
	}
	return 0;
}
