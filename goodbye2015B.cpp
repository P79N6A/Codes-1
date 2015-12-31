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

int cal(int len, ll org, ll line, bool op) {
    ll base = 1;
    int i;
    for (i = 0; i < len - 1; ++i) {
        if (op == 1 && org - base < line) break;
        if (op == 0 && org - base <= line) break;
        base *= 2;
    }
    return i;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll base = 1;
    int ans = 0;
    int down = 0, up = 0;
    for (int i = 1; ; ++i) {
        base *= 2;
        if (base - 1 >= a && !down) { down = i; }
        if (base - 1 >= b) { up = i; break; }
    }

    ll ldown = pow(2, down) - 1, lup = pow(2, up) - 1;

    for (int i = down + 1; i <= up; ++i) ans += i - 1;

    //cout << cal(up, lup, b) << '\n';
    //cout << cal(down, ldown, a) << '\n';

    cout << ans - cal(up, lup, b, 0) + cal(down, ldown, a, 1) << '\n';
    return 0;
}
