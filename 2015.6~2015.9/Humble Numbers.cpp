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
const int MAXN = 6e3;
long long dp[MAXN], p[4] = {2, 3, 5, 7};

void init()
{
    dp[1] = 1;
    for (int i = 2; i <= 5900; ++i)
    {
        dp[i] = 0x7f7f7f7f;
        for (int j = 0; j < 4; ++j)
            for (int k = i - 1; k >= 0; --k)
            {
                if (p[j] * dp[k] <= dp[i - 1])
                    break;
                dp[i] = min(dp[i], dp[k] * p[j]);
            }
    }
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	init();
	int n;
	while (cin >> n && n)
	{
	    cout << "The " << n;
        if (n % 10 == 1 && n % 100 != 11) cout << "st";
        else if (n % 10 == 2 && n % 100 != 12) cout << "nd";
        else if (n % 10 == 3 && n % 100 != 13) cout << "rd";
        else cout << "th";
        cout << " humble number is " << dp[n] << ".\n";
	}
	return 0;
}
