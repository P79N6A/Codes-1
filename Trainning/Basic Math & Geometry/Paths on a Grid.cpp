/*
 画个图，标出每个格点代表的数，很快就能看出是组合数了= =
 然后标记上组合数，就发现是Cn+m取n了。
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

ll C(ll a, ll b) {
    if (b > a - b) b = a - b;
    ll ret = 1;
    int cnt = 0;
    for (ll i = a; i > a - b; --i) {
        ret *= i;
        if (++cnt <= b) {
            ret /= cnt;
        }
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n, m;
    while (cin >> n >> m && (n | m)) {
        cout << C(n + m, n) << '\n';
    }
    return 0;
}
