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
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e3 + 111;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];

    sort(b, b + n);
    for (int i = 0; i < n; ++i) dp[0][i] = abs(a[0] - b[i]);
    int ans1 = INF;
    for (int i = 1; i < n; ++i) {
        int pre = dp[i - 1][0];
        for (int j = 0; j < n; ++j) {
            pre = min(pre, dp[i - 1][j]);
            dp[i][j] = pre + abs(a[i] - b[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        ans1 = min(ans1, dp[n - 1][i]);
    }

    sort(b, b + n, cmp);
    for (int i = 0; i < n; ++i) dp[n - 1][i] = abs(a[n - 1] - b[i]);
    int ans2 = INF;
    for (int i = n - 2; i >= 0; --i) {
        int pre = dp[i + 1][n - 1];
        for (int j = n - 1; j >= 0; --j) {
            pre = min(pre, dp[i + 1][j]);
            dp[i][j] = pre + abs(a[i] - b[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        ans2 = min(ans2, dp[0][i]);
    }

    cout << min(ans1, ans2) << '\n';
    return 0;
}
