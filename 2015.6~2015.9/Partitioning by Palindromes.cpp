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
bool is[MAXN][MAXN];
int dp[MAXN];
string s;

bool isPal(int l, int r)
{
    while ( l < r )
    {
        if (s[l] != s[r])
            return 0;
        ++l, --r;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    int t; cin >> t;
    while ( t-- )
    {
        cin >> s;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= s.length(); ++i)
            for (int j = i; j <= s.length(); ++j)
            {
                is[i][j] = isPal(i - 1,j - 1);
                //if(is[i][j]) cout << i << ' ' << j << endl;
            }
        dp[0] = 0;
        for (int i = 1; i <= s.length(); ++i)
            for (int j = 0; j < i; ++j)
            {
                if(is[j + 1][i])
                {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        cout << dp[s.length()] << '\n';
    }
	return 0;
}


