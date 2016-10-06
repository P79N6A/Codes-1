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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e4 + 111;

struct BIT {
    ll sum[MAXN], n;
    void init(int x) {
        n = x;
        memset(sum, 0, sizeof sum);
    }
    void add(int x, ll val) {
        for (int i = x; i <= n; i += i & -i) sum[i] += val;
    }
    ll get(int x) {
        ll ret = 0;
        for (int i = x; i > 0; i -= i & -i) ret += sum[i];
        return ret;
    }
}bit;

int a[MAXN];
ll ans[101000];
vector<pii> G[MAXN];
map<int, int> mp;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n, q, l, r; cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], G[i].clear();
        cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> l >> r;
            G[r].push_back(make_pair(l, i));
        }
        mp.clear();
        bit.init(n);
        for (int i = 1; i <= n; ++i) {
            if (mp.count(a[i])) bit.add(mp[a[i]], -a[i]);
            bit.add(i, a[i]);
            mp[a[i]] = i;
            for (int j = 0; j < G[i].size(); ++j) {
                int l = G[i][j].first, id = G[i][j].second;
                ans[id] = bit.get(i) - bit.get(l - 1);
            }
        }
        for (int i = 0; i < q; ++i) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
