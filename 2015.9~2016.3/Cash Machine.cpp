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
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

bool dp[MAXN];
int num[15], amount[15];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int cash, n;
    while (~scanf("%d", &cash)) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &num[i], &amount[i]);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (num[i] * amount[i] >= cash) {
                for (int j = amount[i]; j <= cash; ++j)
                    dp[j] |= dp[j - amount[i]];
            }
            else {
                int k = 1;
                while (k < num[i]) {
                    int v = k * amount[i];
                    for (int j = cash; j >= v; --j)
                        dp[j] |= dp[j - v];
                    num[i] -= k;
                    k *= 2;
                }
                int v = num[i] * amount[i];
                for (int j = cash; j >= v; --j) dp[j] |= dp[j - v];
            }
        }

        for (int i = cash; i >= 0; --i) {
            if (dp[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
