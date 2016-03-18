#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MOD = 9901;
const int MAXN = 1e5 + 111;

ll dp[MAXN], a[MAXN], b[MAXN], cnt, n;
map<ll, ll> mp;

void getid(ll b)
{
    if (!mp[b]) mp[b] = ++cnt;
}

ll lowbit(ll x)
{
    return x & -x;
}

ll sum(int x)
{
    ll ret = 0;
    while (x)
    {
        ret = (ret + dp[x]) % MOD;
        x -= lowbit(x);
    }
    return ret;
}

void update(ll x, ll add)
{
    while (x <= n)
    {
        dp[x] = (dp[x] + add) % MOD;
        x += lowbit(x);
    }
}

int main()
{
    ll d, total;
    while (~scanf("%lld%lld", &n, &d))
    {
        cnt = 0;
        mp.clear();
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]), b[i] = a[i];
        sort(b, b + n);
        for (int i = 0; i < n; ++i) getid(b[i]);
        for (int i = 0; i < n; ++i)
        {
            //dp[a[i]] = sum(dp[a[i] - d] + .... + dp[a[i] + d]);
            int l = lower_bound(b, b + n, a[i] - d) - b;
            int r = upper_bound(b, b + n, a[i] + d) - b - 1;
            l = mp[b[l]], r = mp[b[r]];
            total = (sum(r) - sum(l - 1) + 1) % MOD;
            update(mp[a[i]], total);
        }
        printf("%lld\n", (sum(cnt) + 22*MOD - n) % MOD);
    }
    return 0;
}
