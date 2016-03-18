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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int l, u, v, t;
    while (cin >> l >> u >> v >> t && l)
    {
        int lu = u * t, lv = v * t;
        int ans = (lu / (2*l) + lv / (2*l)) / 2;
        lu %= 2 * l, lv %= 2 * l;
        if (lu + lv >= 3 * l) ans += 2;
        else if (lu + lv >= l) ans += 1;
        cout << ans << '\n';
    }
    return 0;
}
