#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MOD = 1e6 + 3;

ll n, k;

ll quick_pow(ll base, ll p) {
    ll ret = 1;
    for (; p; p >>= 1, base = base * base % MOD) {
        if (p & 1) ret = base * ret % MOD;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> n >> k) {
        if (n < 62 && k > (1LL << n)) {
            cout << "1 1\n";
        }
        else {
            ll A = 1, n2 = quick_pow(2, n), cnt = 0;
            for(ll i = k - 1; i; i >>= 1) {
                cnt += (i >> 1);
            }
            if (k < MOD) {
                for (int i = 1; i <= k - 1; ++i) {
                    ll temp = (n2 - i + MOD) % MOD;
                    A = A * temp % MOD;
                }
            }
            else A = 0;
            ll divi = quick_pow(quick_pow(2, cnt), MOD - 2);
            ll B = quick_pow(n2, k - 1);
            A = A * divi % MOD;
            B = B * divi % MOD;
            A = (B - A + MOD) % MOD;
            cout << A << ' ' << B << '\n';
        }
    }
    return 0;
}
