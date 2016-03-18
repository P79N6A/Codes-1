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
ll dp[80][80];

void init()
{
    for (int i = 1; i < 64; ++i)
        for (int j = 1; j < 64; ++j)
            dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i][j - 1];
    return;
}

int main()
{
    ll n, k;
    init();
    while (cin >> k >> n && k)
    {
        if (k > 63) k = 63;
        for (int i = 1; i <= 63; ++i)
        {
            if (dp[k][i] >= n)
            {
                cout << i << '\n';
                goto ed;
            }
        }
        cout << "More than 63 trials needed.\n";
        ed:;
    }
	return 0;
}

