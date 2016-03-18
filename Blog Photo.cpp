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

ll ansh = 0, answ = 0;

void solve1(ll a, ll b) {
    ll base = 1;
    while (base <= a) base *= 2;
    base /= 2;
    ll mx = base * 1.25, mi = ceil(base * 0.8);
    if (mx <= b && base * mx >= ansh * answ) {
        if (base * mx > ansh * answ) {
            ansh = base, answ = mx;
        }
        else if (base > ansh) {
            ansh = base, answ = mx;
        }
    }
    else if (mi <= b && base * b >= ansh * answ) {
        if (base * b > ansh * answ) {
            ansh = base, answ = b;
        }
        else if (base > ansh) {
            ansh = base, answ = b;
        }
    }
    else if (mi > b) {
        solve1(base / 2, b);
    }
}

void solve2(ll a, ll b) {
    ll base = 1;
    while (base < a) base *= 2;
    base /= 2;
    ll mx = base * 1.25, mi = ceil(base * 0.8);
    if (mx <= b && base * mx >= ansh * answ) {
        if (base * mx > ansh * answ) {
            ansh = mx, answ = base;
        }
        else if (mx > ansh) {
            ansh = mx, answ = base;
        }
    }
    else if (mi <= b && base * b >= ansh * answ) {
        if (base * b > ansh * answ) {
            ansh = b, answ = base;
        }
        else if (b > ansh) {
            ansh = b, answ = base;
        }
    }
    else if (mi > b) {
        solve2(base / 2, b);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll h, w;
    while (cin >> h >> w) {
        solve1(h, w);
        solve2(w, h);
        cout << ansh << ' ' << answ << '\n';
    }
    return 0;
}
