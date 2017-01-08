#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 111;

int a[MAXN];
int dp[MAXN][MAXN], sum[MAXN];

int dfs(int i, int j) {
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == j) return ret = 0;
    ret = INF;
    for (int k = i; k < j; ++k) {
        ret = min(ret, dfs(i, k) + dfs(k + 1, j) + sum[j] - sum[i - 1]);
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/in.txt","w",stdout);
    #endif
    string s, ret;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') ret += s[i];
    }
    cout << ret << '\n';

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(1, n) << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}