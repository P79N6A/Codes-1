#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
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
    int t;
    double a, b, s; cin >> t;
    while (t --)
    {
        cin >> a >> b >> s;
        double ans;
        if (a * b <= s) ans = 0;
        else if (s == 0) ans = 1;
        else
        {
            double ss = a * b;
            ans = (ss - s - s * log(ss / s))/ss;
        }
        printf("%.6f%%\n", ans * 100);
    }
    return 0;
}

