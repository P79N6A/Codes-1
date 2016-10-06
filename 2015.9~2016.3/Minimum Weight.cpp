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
#define ll unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 111;

ll sum[MAXN], val[MAXN];

int main()
{
    ll maxVal = (1ULL) << 63;
    sum[0] = val[0] = 0;
    sum[1] = val[1] = 1;
    int up = 2;
    for (int i = 2; sum[i - 1] <= maxVal; ++i) {
        val[i] = 2 * sum[i - 1] + 1;
        sum[i] = val[i] + sum[i - 1];
        ++up;
    }

    ll n, query;
    int k;
    char op[3] = "+-";
    while (~scanf("%llu%d", &n, &k) && (n && k)) {
        int ans = lower_bound(sum, sum + up, n) - sum;
        printf("%d ", ans);
        for (int i = 1; i <= ans; ++i)
            printf("%llu%c", val[i], (i == ans ? '\n' : ' '));

        for (int i = 0; i < k; ++i) {
            scanf("%llu", &query);
            bool flag = 0;
            for (int j = ans; j >= 1; --j) {
                if (sum[j - 1] < query && query <= sum[j]) {
                    printf("%llu", val[j]);
                    if (query < val[j]) {
                        printf("%c", op[!flag]), query = val[j] - query;
                        flag = !flag;
                    }
                    else if (query > val[j]) {
                        printf("%c", op[flag]), query -= val[j];
                    }
                    else break;
                }
            }
            puts("");
        }
    }
    return 0;
}
