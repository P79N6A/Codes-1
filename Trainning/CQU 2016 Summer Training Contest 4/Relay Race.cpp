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

const int MAXN = 311;
int INF = 0;

int dp[MAXN << 1][MAXN][MAXN];
int mp[MAXN][MAXN], n;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    memset(dp, -0x3f, sizeof dp);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &mp[i][j]);
        }
    }
    dp[0][1][1] = mp[1][1];
    int up = 2 * n - 2;
    for (int i = 1; i <= up; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                int y1 = i + 2 - j, y2 = i + 2 - k;
                int add = mp[j][y1] + mp[k][y2];
                if (j == k) add -= mp[j][y1];
                dp[i][j][k] = max(max(dp[i - 1][j][k - 1], dp[i - 1][j][k]),
                                  max(dp[i - 1][j - 1][k], dp[i - 1][j - 1][k - 1])) + add;
            }
        }
    }
    printf("%d\n", dp[up][n][n]);
    return 0;
}
