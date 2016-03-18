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
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 111, UP = 2e6;
int prime[MAXN];
bool is[UP+1];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int len = 0;
    for (ll i = 2; i <= 1300000; ++i)
    {
        if (!is[i])
        {
            prime[len++] = i;
            for (ll j = i * i; j <= 1300000; j += i)
                is[j] = 1;
        }
    }
    int k;
    while (cin >> k && k)
    {
        int p = lower_bound(prime, prime + len, k) - prime;
        if (prime[p] == k)
            cout << 0 << '\n';
        else cout << prime[p] - prime[p - 1] << '\n';
    }
    return 0;
}

