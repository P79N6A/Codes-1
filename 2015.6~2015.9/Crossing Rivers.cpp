#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, d, kase = 0;
    double p, l, v;
    while (cin >> n >> d && (n || d))
    {
        double ans = d;
        for (int i = 0; i < n; ++i)
        {
            cin >> p >> l >> v;
            ans += 2 * l / v;
            ans -= l;
        }
        printf("Case %d: %.3f\n\n", ++kase, ans);
    }
    return 0;
}
