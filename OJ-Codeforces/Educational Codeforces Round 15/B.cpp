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
const int MAXN = 1e5 + 111;

int a[MAXN], p[40];;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> mp;
    ll ans = 0;
    p[0] = 1;
    for (int i = 1; i < 32; ++i) {
        p[i] = p[i - 1] << 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 32; ++j) {
            if (p[j] - a[i] > 0)
                ans += mp[p[j] - a[i]];
        }
        ++mp[a[i]];
    }
    cout << ans << '\n';
    return 0;
}
