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

int s[MAXN];

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int mx = 0;
        for (int i = 0; i < n; ++i) cin >> s[i], mx = max(mx, s[i]);
        if (k >= n)
        {
            cout << mx << '\n';
            continue;
        }
        int ans = 0;
        int lef = 2 * k - n;
        for (int i = n - 1; i >= n - lef; --i) ans = max(ans, s[i]);
        for (int i = 0; i < (n - lef) / 2; ++i)
        {
            ans = max(ans, s[i] + s[n - lef - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
