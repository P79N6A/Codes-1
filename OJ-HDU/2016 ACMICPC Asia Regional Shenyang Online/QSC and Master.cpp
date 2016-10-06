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

const int INF = 0x7f7f7f7f;
const int MAXN = 311;

ll dp[MAXN];
int key[MAXN], val[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t; scanf("%d", &t);
    key[0] = 1;
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &key[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (__gcd(key[i], key[i - 1]) != 1) {
                dp[i] = max(dp[i], dp[i - 2] + val[i] + val[i - 1]);
            }
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
