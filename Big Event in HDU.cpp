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
const int MAXN = 1e6;

int v[111], num[111], dp[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n) && n >= 0) {
        memset(dp, 0, sizeof dp);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &v[i], &num[i]);
            sum += v[i] * num[i];
        }

        int up = sum / 2;

        for (int i = 0; i < n; ++i) {
            if (v[i] * num[i] >= up) {
                for (int j = v[i]; j <= up; ++j) {
                    dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
                }
            }
            else {
                int k = 1;
                while (k < num[i]) {
                    int val = k * v[i];
                    for (int j = up; j >= val; --j) {
                        dp[j] = max(dp[j], dp[j - val] + val);
                    }
                    num[i] -= k;
                    k = k * 2;
                }
                int val = num[i] * v[i];
                for (int j = up; j >= val; --j) {
                    dp[j] = max(dp[j], dp[j - val] + val);
                }
            }
        }

        printf("%d %d\n", sum - dp[up], dp[up]);
    }
    return 0;
}
