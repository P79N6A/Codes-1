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
const int MAXN = 1e6 + 111;

ll cnt(ll x) {
    if (x < 10) return x;
    int last = x % 10;
    ll ret = x / 10 + 9;
    while (x >= 10) x /= 10;
    if (x > last) --ret;
    return ret;
}

int main()
{
    ll l, r;
    while (cin >> l >> r) {
        cout << cnt(r) - cnt(l - 1) << '\n';
    }
    return 0;
}
