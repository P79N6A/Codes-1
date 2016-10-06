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
const int MAXN = 111;

int a[MAXN];
int b[MAXN];
int dp[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2) b[i] = 0;
            else {
                int j;
                for (j = log2(a[i]); j >= 1; --j) {
                    if (a[i] % (int)pow(2, j) == 0) {
                        break;
                    }
                }
                b[i] = j;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            dp[i] = b[i];
            for (int j = 0; j < i; ++j) {
//                dp[i] = max(dp[i], dp[j]);
                if (a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + b[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
