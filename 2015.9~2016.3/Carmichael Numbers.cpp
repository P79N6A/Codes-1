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

bool quick_pow(int x, int p) {
    int mod = p;
    ll base = x;
    ll judge = 1;
    while (p) {
        if (p & 1) judge = judge * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return judge == x;
}

bool ok(int n) {
    bool flag = 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    if (flag) return 0;

    for (int i = 2; i < n; ++i) {
        if (!quick_pow(i, n)) return 0;
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n && n) {
        if (ok(n)) cout << "The number " << n << " is a Carmichael number.\n";
        else cout << n << " is normal.\n";
    }
    return 0;
}
