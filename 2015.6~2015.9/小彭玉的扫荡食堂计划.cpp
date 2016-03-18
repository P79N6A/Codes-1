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
const int MAXN = 1111;
int a[MAXN];
int dp[10100];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, m;
	while( cin >> n )
	{
	    memset(dp, 0, sizeof dp);
	    for(int i = 0; i < n; ++i)
	    {
	        cin >> a[i];
        }
        cin >> m;
        sort(a, a + n);
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = m - 5; j >= a[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        if(m < 5) cout << m << '\n';
        else cout << m - dp[m - 5] - a[n - 1] << '\n';
    }
	return 0;
}


