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
const int MAXN = 211;

int a[MAXN], c[MAXN];
bool dp[100100];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (scanf("%d%d", &n, &m) && (n | m)) {
        for (int i = 0; i < n; ++i) scanf("%d", c + i);
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        memset(dp, 0, sizeof(bool) * (m + 2));
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            if (c[i] * a[i] >= m) {
                for (int j = c[i]; j <= m; ++j) {
                    dp[j] |= dp[j - c[i]];
                }
            }
            else {
                int cnt = 1;
                while (cnt <= a[i]) {
                    int x = cnt * c[i];
                    for (int j = m; j >= x; --j) {
                        dp[j] |= dp[j - x];
                    }
                    a[i] -= cnt;
                    cnt <<= 1;
                }
                int x = a[i] * c[i];
                for (int j = m; j >= x; --j) {
                    dp[j] |= dp[j - x];
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (dp[i]) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
