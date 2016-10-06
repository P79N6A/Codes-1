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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1e3 + 111;

int a[MAXN], dp[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
