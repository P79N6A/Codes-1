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
const int MAXN = 1e4 + 111;

ll x[MAXN], p;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll t, n, m, k; scanf("%I64d", &t);
    while (t --)
    {
        ll sum = 0;
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) scanf("%I64d", &x[i]);
        for (int i = 0; i < m; ++i) scanf("%I64d", &p), sum += x[p], x[p] = 0;
        if (sum > k) printf("-1\n");
        else
        {
            k -= sum;
            int ans = 0;
            sort(x + 1, x + n + 1);
            for (int i = 1; i <= n; ++i)
            {
                if (k - x[i] >= 0) ++ans, k -= x[i];
                else break;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
