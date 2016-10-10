#include<algorithm>
#include<bitset>
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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;

ll getsum(ll x, ll mul) {
    return (1 + x) * x / 2 * mul;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    ll n;
    while (t --) {
        scanf("%lld", &n);
        --n;
        ll sum = getsum(n / 3, 3) + getsum(n / 5, 5) - getsum(n / 15, 15);
        printf("%lld\n", sum);
    }
    return 0;
}
