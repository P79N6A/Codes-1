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

int num, dp[MAXN];

int main()
{
    int n, len = 0, mx = 0, ans = 0;
    scanf("%d", &n);
    memset(dp, 0x7f, sizeof dp);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        if (num >= mx) ++len;
        else
        {
            ans = max(ans, len);
            len = 1;
        }
        mx = num;
    }
    ans = max(ans, len);
    printf("%d\n", ans);
    return 0;
}
