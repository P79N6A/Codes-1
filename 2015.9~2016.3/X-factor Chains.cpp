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

ll fac(ll x) {
    ll ret = 1;
    for (ll i = 2; i <= x; ++i) {
        ret *= i;
    }
    return ret;
}

int main()
{
    int n;
    while (cin >> n) {
        vector<int> time;
        ll ans = 0, anst = 0;
        ll i = 2;
        while (n != 1) {
            bool flag = 1;
            for (;i * i <= n; ++i) {
                if (n % i == 0) {
                    flag = 0;
                    int t = 0;
                    while (n % i == 0) {
                        n /= i;
                        ++t;
                    }
                    time.push_back(t);
                    ans += t;
                    break;
                }
            }
            if (flag) {
                ++ans;
                time.push_back(1);
                n = 1;
            }
        }
        anst = fac(ans);
        for (int i = 0; i < time.size(); ++i) {
            anst /= fac(time[i]);
        }
        cout << ans << ' ' << anst << '\n';
    }
    return 0;
}
