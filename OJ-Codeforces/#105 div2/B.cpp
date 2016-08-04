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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double vp, vd, t, f, c;
    while (cin >> vp >> vd >> t >> f >> c) {
        double st = t * vp;
        double del = vd - vp;
        if (del <= 0) {
            puts("0");
            continue;
        }
        int ans = 0;
        while (1) {
            double time = st / del;
            st += time * vp;
            if (st >= c) break;
            ++ans;
            st += vp * (f + st / vd);
        }
        cout << ans << '\n';
    }
    return 0;
}
