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
const int MAXN = 91;
int t[MAXN];
int dp[300][60];
bool has[600][60][2];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, T, m1, m2, d1, d2, kase = 0;
	while ( cin >> n && n )
	{
	    memset(has, 0, sizeof has);
	    cin >> T;
        for (int i = 2; i <= n; ++i)
            cin >> t[i];
        cin >> m1;
        for (int i = 1; i <= m1; ++i)
        {
            cin >> d1; has[d1][1][0] = 1;
            for (int j = 2; j <= n; ++j)
            {
                d1 += t[j];
                has[d1][j][0] = 1;
            }
        }
        cin >> m2;
        for (int i = 1; i <= m2; ++i)
        {
            cin >> d2; has[d2][n][1] = 1;
            for (int j = n - 1; j >= 1; --j)
            {
                d2 += t[j + 1];
                has[d2][j][1] = 1;
            }
        }
        memset(dp, 0x3f, sizeof dp);
        dp[T][n] = 0;
        for (int i = T - 1; i >= 0; --i)
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i + 1][j] + 1;
                if (j > 1 && has[i][j][1] && i + t[j] <= T)
                    dp[i][j] = min(dp[i][j], dp[i + t[j]][j - 1]);
                if (j < n && has[i][j][0] && i + t[j + 1] <= T)
                    dp[i][j] = min(dp[i][j], dp[i + t[j + 1]][j + 1]);
            }
        cout << "Case Number " << ++kase << ": ";
        if (dp[0][1] >= 0x3f3f3f3f) cout << "impossible\n";
        else cout << dp[0][1] << '\n';
    }
	return 0;
}


