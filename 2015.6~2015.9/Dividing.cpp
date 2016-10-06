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
const int MAXN = 1e5;
int num[7];
int dp[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int kase = 0;
	while(1)
    {
	    bool flag = 1;
	    int sum = 0;
	    for (int i = 1; i <= 6; ++i)
	    {
	        cin >> num[i];
	        sum += num[i] * i;
	        if (num[i] > 0) flag = 0;
	    }
	    if (flag) break;
	    cout << "Collection #" << ++kase << ":\n";
	    if (sum % 2) cout << "Can't be divided.\n\n";
	    else
	    {
            int n = sum / 2;
	        memset(dp, -0x3f, sizeof dp);
            dp[0] = 0;
            for (int i = 1; i <= 6; ++i)
            {
                if (num[i] == 0) continue;
                if (num[i] * i >= n)
                {
                    for (int j = i; j <= n; ++j)
                        dp[j] = max(dp[j], dp[j - i] + i);
                }
                else
                {
                    int k = 1;
                    while (k < num[i])
                    {
                        for (int j = n; j >= k * i; --j)
                            dp[j] = max(dp[j], dp[j - k*i] + k*i);
                        num[i] -= k;
                        k *= 2;
                    }
                    for (int j = n; j >= num[i] * i; --j)
                        dp[j] = max(dp[j], dp[j - num[i]*i] +num[i]*i);
                }
            }
            if (dp[n] > 0) cout << "Can be divided.\n\n";
            else cout << "Can't be divided.\n\n";
        }
	}
	return 0;
}


