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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1111;
string s;
int n, dp[MAXN][MAXN];

void dfs(int l, int r)
{
    if (l > r) return;
    if (l == r) {cout << s[l]; return;}
    if (s[l] == s[r])
    {
        cout << s[l];
        dfs(l + 1, r - 1);
        cout << s[r];
    }
    else if (dp[l][r] == dp[l + 1][r] + 1) //说明是从变成s[l] + dp[l + 1][r] + s[l]
    {
        cout << s[l];
        dfs(l + 1, r);
        cout << s[l];
    }
    else
    {
        cout << s[r];
        dfs(l, r - 1);
        cout << s[r];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> s)
    {
        n = s.length();
        memset(dp, 0, sizeof dp);
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        cout << dp[0][n - 1] << ' ';
        dfs(0, n - 1);
        cout << '\n';
    }
    return 0;
}

