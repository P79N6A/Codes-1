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
using namespace std;

const int MAXN = 1e5;

struct Cow{
    int s, f;
}cow[150];
int dp[2 * MAXN + 100];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cow[i].s >> cow[i].f;
    }

    int center = 1000 * n;   // 防止负数容量特设的起始点
    int up = center * 2 + 20; // 背包容量上限
    memset(dp, -0x3f, sizeof(int) * (up + 1));
    dp[center] = 0;

    for (int i = 0; i < n; ++i) {
        if (cow[i].s < 0) {
            for (int j = 0; j <= up + cow[i].s; ++j) {
                dp[j] = max(dp[j], dp[j - cow[i].s] + cow[i].f);
            }
        }
        else {
            for (int j = up; j >= cow[i].s; --j) {
                dp[j] = max(dp[j], dp[j - cow[i].s] + cow[i].f);
            }
        }
    }
    int ans = 0;
    for (int i = center; i <= up; ++i) {
        // 如果状态存在，且大于最大值
        if (dp[i] >= 0 && dp[i]  + i - center > ans)
            ans = dp[i] + i - center;
    }

    cout << ans << '\n';
    return 0;
}
