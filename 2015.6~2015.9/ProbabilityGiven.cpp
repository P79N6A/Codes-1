#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
double p[22], b[22];
int a[22];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, r, kase = 0;
    while (cin >> n >> r && (n||r))
    {
        for (int i = 0; i < n; ++i) cin >> p[i], b[i] = 0;
        for (int i = 0; i < r; ++i) a[i] = 1;
        for (int i = r; i < n; ++i) a[i] = 0;
        double ans = 0;
        do
        {
            double t = 1;
            for (int i = 0; i < n; ++i) t *= (a[i] == 1? p[i]:1-p[i]);
            for (int i = 0; i < n; ++i) if (a[i]) b[i] += t;
            ans += t;
        }while( prev_permutation(a, a + n));
        cout << "Case " << ++kase << ":\n";
        for (int i = 0; i < n; ++i)
            cout << setprecision(6) << b[i]/ans << '\n';
    }
    return 0;
}
