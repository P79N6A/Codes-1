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
const int MAXN = 1e6 + 111;
const int MOD = 1e9 + 7;

inline ll power(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        p >>= 1;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k; cin >> k;
    ll x, n = 2;
    bool odd = 1;
    while (k --) {
        cin >> x;
        if (!(x & 1)) odd = 0;
        n = power(n, x);
    }
    n = n * power(2, MOD - 2) % MOD;
    cout << (n + (odd ? -1 : 1)) * power(3, MOD - 2) % MOD << '/' << n << '\n';
    return 0;
}
