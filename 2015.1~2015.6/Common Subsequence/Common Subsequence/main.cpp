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
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define bug puts("I am bug")
#define xy(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;
const int MAXN = 1000;

int dp[MAXN][MAXN];

int main() {
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= s1.size(); ++i)
            for (int j = 1; j <= s2.size(); ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        cout << dp[s1.size()][s2.size()] << '\n';
    }
    return 0;
}
