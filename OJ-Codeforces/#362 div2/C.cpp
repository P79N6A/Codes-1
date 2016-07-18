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

map<ll, ll> mp;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    ll op, u, v, w;
    while (q --) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v >> w;
            while (u / 2 != v / 2) {
                if (u / 2 < v / 2) {
                    swap(u, v);
                }
                while (u / 2 > v / 2) {
                    ll p = u / 2;
                    mp[u] += w;
                    u /= 2;
                }
            }
            if (u != v) {
                mp[u] += w;
                mp[v] += w;
            }
        }
        else {
            cin >> u >> v;
            ll ans = 0;
            while (u / 2 != v / 2) {
                if (u / 2 < v / 2) {
                    swap(u, v);
                }
                while (u / 2 > v / 2) {
                    ll p = u / 2;
                    ans += mp[u];
                    u /= 2;
                }
            }
            if (u != v) {
                ans += mp[u] + mp[v];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
