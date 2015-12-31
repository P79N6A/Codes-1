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
const int MAXN = 1e8 + 111;

vector<ll> prime;
bool is[MAXN];

void init()
{
    prime.push_back(-1000);
    for (ll i = 2; i <= 1e5; ++i)
    {
        if (!is[i])
        {
            for (ll j = i * i; j <= 1e5; j += i)
            {
                is[j] = 1;
            }
            prime.push_back(i * i);
        }
    }
}

int main()
{
    int t, n;
    init();
    cin >> t;
    while (t --)
    {
        cin >> n;
        int x = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
        if (n - prime[x - 1] <= prime[x] - n) cout << prime[x - 1] << '\n';
        else cout << prime[x] << '\n';
    }
    return 0;
}
