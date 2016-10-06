#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 111;
ll prime[MAXN], len;
bool is[MAXN];

void seive()
{
    for (ll i = 2; i < MAXN; ++i) if(!is[i])
    {
        prime[len++] = i;
        for (ll j = i * i; j < MAXN; j+= i)
            is[j] = 1;
    }
}

ll solve(ll n)
{
    ll cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        ll cur = prime[i] * prime[i];
        while (cur < n)
        {
            ++cnt;
            cur *= prime[i];
        }
    }
    return cnt;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    seive();
    int t; cin >> t;
    ll l, r;
    while (t --)
    {
        cin >> l >> r;
        cout << solve(r + 1) - solve(l) << '\n';
    }
    return 0;
}
