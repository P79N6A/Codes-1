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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

ll base[MAXN];

ll dfs(ll n, ll r, ll s, ll e) {
    if (n == 0) return 1;
    ll ret = 0;
    ll num = base[n] / 2;

    if (r < num) {
        if (e < num) ret = dfs(n - 1, r, s, e);
        else if (s >= num) ret = dfs(n - 1, r, s - num, e - num);
        else ret = dfs(n - 1, r, s, num - 1) + dfs(n - 1, r, 0, e - num);
    }
    else {
        if (e < num) ret = dfs(n - 1, r - num, s, e);
        else if (s >= num) ret = -dfs(n - 1, r - num, s - num, e - num);
        else ret = dfs(n - 1, r - num, s, num - 1) - dfs(n - 1, r - num, 0, e - num);
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n, r, s, e;
    base[0] = 1;
    for (int i = 1; i <= 60; ++i) base[i] = base[i - 1] * 2;

    while (cin >> n >> r >> s >> e) {
        if (n == -1 && r == -1 && s == -1 && e == -1) break;
        cout << dfs(n, r, s, e) << '\n';
    }
    return 0;
}
