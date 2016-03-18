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
#define pii pair<int, int>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 611;

struct P {
    int mi, mx, x;
    P(int a, int b, int c): mi(a), mx(b), x(c){}
    bool operator < (const P &t)const {
        return x < t.x;
    }
};
vector<P> hor, ver;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x1, y1, x2, y2;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) ver.push_back(P(min(y1,y2),max(y1,y2), x1));
        else hor.push_back(P(min(x1,x2), max(x1,x2), y1));
    }
    sort(hor.begin(), hor.end());

    ll ans = 0;
    for (int i = 0; i < ver.size(); ++i) {
        for (int j = i + 1; j < ver.size(); ++j) {
            int l = min(ver[i].x, ver[j].x);
            int r = max(ver[i].x, ver[j].x);
            int up = min(ver[i].mx, ver[j].mx);
            int down = max(ver[i].mi, ver[j].mi);
            if (l == r || up == down) continue;
            //pr(l);pr(r);pr(up);pr(down);
            //cout << "begin:\n";
            int lef = lower_bound(hor.begin(), hor.end(), P(0, 0, down)) - hor.begin();
            int rig = upper_bound(hor.begin(), hor.end(), P(0, 0, up)) - hor.begin();
            ll ret = 0;
            for (int k = lef; k < rig; ++k) {
                P &t = hor[k];
               // cout << t.x << ',' << t.mi << ',' << t.mx << endl;
                if (t.x <= up && t.x >= down && t.mi <= l && t.mx >= r) ++ret;
            }
            ans += ret * (ret - 1) / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
