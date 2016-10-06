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
int dp[20][20];

void init()
{
    dp[0][0] = 1;
    for(int i = 1; i <= 10; ++i)
        for(int j = 0; j < 10; ++j)
            for(int k = 0; k < 10; ++k)
            {
                if(j != 4 && !(j == 3 && k == 7))
                    dp[i][j] += dp[i - 1][k];
            }
}

int solve(int n)
{
    int digit[20];
    int len = 0;
    while(n)
    {
        digit[++len] = n % 10;
        n /= 10;
    }
    digit[len + 1] = 0;
    int ans = 0;
    for(int i = len; i ; --i)
    {
        for(int j = 0; j < digit[i]; ++j)//以j开头的i位数
        {
            if(j != 4 && !(digit[i + 1] == 3 && j == 7) )
                ans += dp[i][j];
        }
        if(digit[i]==4||(digit[i + 1] == 3 && digit[i + 1] == 7)) //dp已经被处理为前i - 1项满足的数量，
            break;                                               //所以当前如果是讨厌的数字，就可以结束整个过程
    }
    return ans;
}

int main()
{
    int l, r;
    cin >> l >> r;
    init();
    cout << solve(r + 1) - solve(l) << '\n';
	return 0;
}


