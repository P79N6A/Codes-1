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

ll mxx, mxy, mix, miy, x, y;

int main()
{
    int n; cin >> n;
    mxx = mxy = -INF, mix = miy = INF;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        mxx = max(mxx, x);
        mix = min(mix, x);
        mxy = max(mxy, y);
        miy = min(miy, y);
    }
    ll ok = max(mxx - mix, mxy - miy);
    cout << ok * ok << '\n';
    return 0;
}
