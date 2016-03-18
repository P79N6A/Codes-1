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

ll p, a;

bool ok() {
    bool flag = 1;
    for (int i = 2; i <= sqrt(p); ++i) {
        if (p % i == 0) {
            flag = 0;
            break;
        }
    }
    if (flag) return 0;

    ll x = p;
    ll base = a;
    ll sum = 1;
    while (x) {
        if (x & 1) {
            sum = (sum * base) % p;
        }
        x >>= 1;
        base = (base * base) % p;
    }
    return sum == a;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> p >> a && (p | a)) {
        if (ok()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
