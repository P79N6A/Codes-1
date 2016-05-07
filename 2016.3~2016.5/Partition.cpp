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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int mod = 1e9 + 7;

ll quick_pow(ll base, int indx) {
    ll ret = 1;
    while (indx) {
        if (indx & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        indx /= 2;
    }
    return ret;
}

int main()
{
    int n, k, t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        if (n < k) printf("0\n");
        else {
            ll ans = quick_pow(2, n - k);
            if (n - k - 2 >= 0)
                ans += quick_pow(2, n - k - 2) * (n - k - 1);
            printf("%lld\n", ans % mod);
        }
    }
    return 0;
}
