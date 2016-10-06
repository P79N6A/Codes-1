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

int main()
{
    ll s, d;
    ll sday, dday;
    while (cin >> s >> d) {
        for (ll i = 0; i <= 5; ++i) {
            if (s * (5 - i) - d * i < 0) {
                sday = 5 - i;
                dday = i;
                break;
            }
        }

        ll ans;
        if (dday <= 3)
            ans = (sday * 2 + 2) * s - (dday * 2) * d;
        else if (dday == 4)
            ans = (sday * 2 + 1) * s - (dday * 2 + 1) * d;
        else ans = -(dday * 2 + 2) * d;

        if (ans < 0) cout << "Deficit\n";
        else cout << ans << '\n';
    }
    return 0;
}
