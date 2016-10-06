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
const int MAXN = 1e3 + 111;
int dp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	string a, b;
	while (cin >> a >> b)
	{
	    memset(dp, 0, sizeof dp);
	    for (int i = 0; i < a.length(); ++i)
            for (int j = 0; j < b.length(); ++j)
            {
                if (a[i] == b[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        cout << dp[a.length()][b.length()] << '\n';
	}
	return 0;
}


