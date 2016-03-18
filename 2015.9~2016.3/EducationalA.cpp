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
const int MAXN = 1e6 + 111;

int main()
{
    ll t, n;
    scanf("%I64D", &t);
    while (t --)
    {
        scanf("%I64d", &n);
        ll sum = (1 + n) * (n) / 2;
        int c = 0;
        while ((1 << c) <= n)
        {
            ++c;
        }
        printf("%I64d\n", sum - 2 * (ll)pow(2, c) + 2);
    }
    return 0;
}
