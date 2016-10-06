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

vector<ll> l, r;

int main()
{
    int k;
    string s;
    while (cin >> k >> s) {
        ll cnt = 0, lef = 0;
        r.clear(), l.clear();
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                l.push_back(cnt);
                cnt = 0;
            }
            else ++cnt;
        }

        cnt = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '1') {
                r.push_back(cnt);
                cnt = 0;
            }
            else ++cnt;
        }
        lef = cnt;
        reverse(r.begin(), r.end());

        ll ans = max(0, (int)(r.size() - k + 1));
        if (k >= 1) {
            for (int i = k - 1; i < r.size(); ++i) {
                ans += r[i] + l[i - k + 1] + r[i] * l[i - k + 1];
                //cout << r[i] << ' ' << l[l.size() - i - 1] << endl;
            }
        }
        else {
            ans = (lef + 1) * lef / 2;
            for (int i = 0; i < r.size(); ++i)
                ans += (r[i] + 1) * r[i] / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
