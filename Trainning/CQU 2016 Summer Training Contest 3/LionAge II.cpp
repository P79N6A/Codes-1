#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

string s;
int dp[MAXN][26][MAXN];
int mp[26][26];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, w;
    char u, v;
    cin >> s >> k >> n;
    memset(mp, 0, sizeof mp);
    memset(dp, -0x3f, sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin >> u >> v >> w;
        mp[u - 'a'][v - 'a'] = w;
    }
    dp[0][s[0] - 'a'][0] = 0;
    for (int i = 0; i < 26; ++i) {
        if (i != s[0] - 'a') dp[0][i][1] = 0;
    }
    for (int i = 1; i < s.length(); ++i) {
        int u = s[i - 1] - 'a', v = s[i] - 'a';
        dp[i][v][0] = dp[i - 1][u][0];
        dp[i][v][0] += mp[u][v];
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j < s.length(); ++j) {
            for (int c = 0; c < 26; ++c) {
                if (c == s[j] - 'a') {
                    for (int x = 0; x < 26; ++x) {
                        dp[j][c][i] = max(dp[j][c][i], dp[j - 1][x][i] + mp[x][c]);
                    }
                }
                else {
                    for (int x = 0; x < 26; ++x) {
                        dp[j][c][i] = max(dp[j][c][i], dp[j - 1][x][i - 1] + mp[x][c]);
                    }
                }
            }
        }
    }
    int ans = -INF, last = s.length() - 1;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <= k; ++j)
            ans = max(ans, dp[last][i][j]);
    }
    printf("%d\n", ans);
    return 0;
}
