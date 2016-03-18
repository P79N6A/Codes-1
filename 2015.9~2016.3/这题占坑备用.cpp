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
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

vector<ll> ans;

int getlen(ll x)
{
    int ret = 0;
    while (x)
    {
        ++ret;
        x /= 10;
    }
    return ret;
}

void dfs(ll x)
{
    for (ll i = 2; i <= 18; ++i)
    {
        if (i * x > 1e18) break;
        ll temp = i * x;
        if (getlen(temp) == i)
        {
            ans.push_back(temp);
            dfs(temp);
        }
    }
}

void init()
{
    for (int i = 0; i < 10; ++i)
    {
        ans.push_back(i);
        if (i >= 5)
        {
            dfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
}

int main()
{
    init();
    ll l, r;
    while (~scanf("%lld %lld", &l, &r))
    {
        printf("%d\n", upper_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l));
    }
    return 0;
}
