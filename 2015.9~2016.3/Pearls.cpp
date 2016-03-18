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
const int MAXN = 211;

int a[MAXN], p[MAXN], sum[MAXN], dp[MAXN];

int main()
{
    int kase, n; scanf("%d", &kase);
    while (kase --) {
        scanf("%d", &n);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i], &p[i]);
            sum[i] = sum[i - 1] + a[i];
            dp[i] = INF;
        }

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j)
                dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * p[i]);
        }

        printf("%d\n", dp[n]);
    }
    return 0;
}
