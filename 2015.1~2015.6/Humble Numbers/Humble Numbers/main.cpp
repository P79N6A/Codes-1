#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

ll dp[6000];
int p[4] = {2, 3, 5, 7};

int main() {
    dp[1] = 1;
    for (int i = 2; i <= 5900; ++i)
    {
        dp[i] = 0x7f7f7f7f;
        for (int j = 0; j < 4; ++j)
        {
            for (int k = i - 1; k >= 1; --k)
            {
                if (dp[k] * p[j] <= dp[i - 1])
                    break;
                if (dp[k] * p[j] < dp[i])
                    dp[i] = dp[k] * p[j];
            }
        }
    }
    int n;
    while (cin >> n && n)
    {
        cout << "The "<< n;
        if (n % 10 == 1 && n % 100 != 11)
            cout << "st ";
        else if (n % 10 == 2 && n % 100 != 12)
            cout << "nd ";
        else if (n % 10 == 3 && n % 100 != 13)
            cout << "rd ";
        else cout << "th ";
        cout << "humble number is " << dp[n] << ".\n";
    }
    return 0;
}
