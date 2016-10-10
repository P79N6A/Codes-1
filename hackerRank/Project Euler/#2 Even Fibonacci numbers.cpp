#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    ll n;
    while (t --) {
        cin >> n;
        ll a = 0, b = 1;
        ll ans = 0;
        while (a + b < n) {
            ll c = a + b;
            if (c % 2 == 0) ans += c;
            a = b;
            b = c;
        }
        cout << ans << '\n';
    }
    return 0;
}
