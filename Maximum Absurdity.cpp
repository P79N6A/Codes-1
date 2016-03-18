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
const int MAXN = 2e5 + 111;

ll a[MAXN], getv[MAXN];
struct P {
    ll val, pos; // 记录位置和和
}dp[MAXN];

int main()
{
    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; ++i) cin >> a[i];

        ll sum = 0;
        for (int i = 1; i <= k; ++i) sum += a[i];
        getv[1] = sum;
        for (int i = k + 1; i <= n; ++i) {
            sum += a[i] - a[i - k];
            getv[i - k + 1] = sum;
        }

        dp[n - k + 1].val = getv[n - k + 1];
        dp[n - k + 1].pos = n - k + 1;
        for (int i = n - k; i > k; --i) {
            if (getv[i] >= dp[i + 1].val) {
                dp[i].val = getv[i];
                dp[i].pos = i;
            }
            else {
                dp[i].val = dp[i + 1].val;
                dp[i].pos = dp[i + 1].pos;
            }
        }
        int a = 0, b = 0;
        ll mx = 0;
        for (int i = k + 1; i <= n - k + 1; ++i) {
            ll sum = getv[i - k] + dp[i].val;
            if (sum > mx) {
                mx = sum;
                a = i - k;
                b = dp[i].pos;
            }
        }

        cout << a << ' ' << b << '\n';
    }
    return 0;
}
