/*
 所有约数的和 = (1 + p1^1 + ... + p1^n1) * (1 + p2^1 + ... + p2^n2) * ...
 A^B中的B只是给A的质因子增长了而已， A = p1^a*p2^b*...
 1 + p1^1 + ... + p1^n1 使用折半的方法计算
*/
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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4;
const int MOD = 9901;

vector<int> prime;
void init() {
    for (int i = 2; i <= MAXN; ++i) {
        bool flag = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        prime.push_back(i);
    }
}

int fac[1111], cnt[1111], indx = 0;
void prePro(ll x) {
    indx = 0;
    for (int i = 0; prime[i] <= x / prime[i]; ++i) {
        if (x % prime[i] == 0) {
            cnt[indx] = 0;
            fac[indx] = prime[i];
            while (x % prime[i] == 0) {
                x /= prime[i];
                ++cnt[indx];
            }
            ++indx;
        }
    }
    if (x != 1) {
        cnt[indx] = 1;
        fac[indx++] = x;
    }
}

ll quick_pow(ll base, ll p) {
    ll ret = 1;
//    pr(base)pr(p)
    while (p) {
        if (p & 1) {
            ret = ret * base % MOD;
        }
        base = base * base % MOD;
        p /= 2;
    }
//    pr(ret)
    return ret;
}

ll getAns(ll base, ll p) {
    if (base == 0) return 0;
    if (p == 0) return 1;
    if (p & 1) {
        return ((1+quick_pow(base,p/2+1))%MOD*getAns(base,p/2))%MOD;
    }
    return (((1+quick_pow(base, p/2+1))%MOD*getAns(base, p/2-1))%MOD+quick_pow(base,p/2)%MOD)%MOD;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    ll a, b;
    init();
    while (cin >> a >> b) {
        prePro(a);
        //pr(fac[0])pr(cnt[0])
        ll ans = 1;
        for (int i = 0; i < indx; ++i) {
            ans *= getAns(fac[i], b * cnt[i]);
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
