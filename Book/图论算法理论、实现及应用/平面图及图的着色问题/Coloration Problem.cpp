/*
 * 用b种颜色给边长为a的等边三角形中的边长为1的等边三角形染色，有多少方法？
 */
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e3 + 111;

int p[10];
// dp[0]:偶数位上的三角形，dp[1]:奇数位上的三角形
// dp[i][j][k]:到第j行，状态为k的染色有多少种方法
ll dp[2][7][MAXN], a, b;

bool ok(int x, int y, int len) {
    while (len-- > 1) {
        if (x % b == y % b) return 0;
        x /= b, y /= b;
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    p[1] = 1;
    while (cin >> a >> b && a) {
        for (int i = 2; i <= 7; ++i) p[i] = p[i - 1] * b;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < b; ++i) dp[1][1][i] = 1;
        for (int i = 2; i <= a; ++i) {
            // 当前行偶数位受上一行奇数位影响
            for (int j = 0; j < p[i]; ++j) {
                for (int k = 0; k < p[i]; ++k) {
                    if (ok(j, k, i))
                        dp[0][i][j] += dp[1][i - 1][k];
                }
            }
            // 当前行奇数位受当前行偶数位影响
            for (int j = 0; j < p[i + 1]; ++j) {
                for (int k = 0; k < p[i]; ++k) {
                    if (ok(j / b, k, i) && ok(j % p[i], k, i))
                        dp[1][i][j] += dp[0][i][k];
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < p[a + 1]; ++i) {
            ans += dp[1][a][i];
        }
        cout << ans << '\n';
    }
    return 0;
}
