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
const int MAXN = 1e5 + 111;

ll x[MAXN];
map<ll, ll> cnt, ans;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n; cin >> t;
    ll k;
    while (t --) {
        cnt.clear(), ans.clear();
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> x[i];
        ll ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            ret += ans[x[i] * k];
            ans[x[i]] += cnt[x[i] * k];
            ++cnt[x[i]];
        }
        cout << ret << '\n';
    }
    return 0;
}
