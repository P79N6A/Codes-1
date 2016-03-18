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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
int num[MAXN], dp[MAXN];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i], dp[i] = 1;

    int ans = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
        {
            if (num[j] + 1 == num[i])
            {
                dp[i] += dp[j];
                ans = max(ans, dp[i]);
                break;
            }
        }

    cout << n - ans << '\n';
    return 0;
}
