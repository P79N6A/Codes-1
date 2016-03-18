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
const int MAXN = 1e5 + 111;

map<double, ll> mp, mp2;

int rev(int x) {
    int ret = 0;
    while (x) {
        ret = x % 10 + ret * 10;
        x /= 10;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    ll mxx, mxy, w, cnt = 0;
    cin >> mxx >> mxy >> w;
    for (int i = 1; i <= mxx; ++i) ++mp[i * 1.0 / rev(i)];
    for (int j = 1; j <= mxy; ++j) cnt += mp[1.0 * rev(j) / j];
    if (cnt < w) {cout << -1 << '\n'; return 0;}

    ll tx = mxx, ty = 1, ax = mxx, ay = mxy;
    double temp;
    cnt = mp[1.0]; ++mp2[1.0];
    while (tx >= 1 && ty <= mxy) {
        if (cnt >= w) {
            if (tx * ty < ax * ay) ax = tx, ay = ty;
            temp = 1.0 * tx / rev(tx);
            cnt -= mp2[temp];
            --mp[temp];
            --tx;
        }
        else {
            ++ty;
            temp = 1.0 * rev(ty) / ty;
            cnt += mp[temp];
            ++mp2[temp];
        }
    }
    cout << ax << ' ' << ay << '\n';
    return 0;
}
