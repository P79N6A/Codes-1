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

ll need[3], num[3], price[3], rul;

bool ok(ll sum) {
    ll ret = 0;
    for (int i = 0; i < 3; ++i) {
        ret += (sum * need[i] - min(sum * need[i], num[i])) * price[i];
    }
    return ret <= rul;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        switch(s[i]) {
            case 'B': ++need[0]; break;
            case 'S': ++need[1]; break;
            case 'C': ++need[2]; break;
        }
    }
    for (int i = 0; i < 3; ++i) cin >> num[i];
    for (int i = 0; i < 3; ++i) cin >> price[i];
    cin >> rul;
    ll ans = 0, l = 0, r = 1e12 + 1e3;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
