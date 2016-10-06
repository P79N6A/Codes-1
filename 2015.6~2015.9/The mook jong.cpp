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
ll dp[70];

void init()
{
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= 60; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j <= i - 3; ++j)
            dp[i] += dp[j];
    }
    for (int i = 2; i <= 60; ++i)
    {
        dp[i] += dp[i - 1];
    }
}

int main()
{
    init();
    int n;
    while (cin >> n)
    {
        cout << dp[n] << '\n';
    }
	return 0;
}

