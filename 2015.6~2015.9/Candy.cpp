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
#define double long double
const int INF = 0x7f7f7f7f, MAXN = 4e5 + 111;
int kase, n;
double p, lg[MAXN], ans;

void init()
{
    for (int i = 2; i < MAXN; ++i) lg[i] = lg[i - 1] + log(i);
}

double c(int a, int b)
{
    return lg[a] - lg[b] - lg[a - b];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    while (cin >> n >> p)
    {
        if (p == 0 || p == 1) ans = n;
        else
        {
            ans = 0;
            double a = log(p), b = log(1 - p);
            for (int i = 1; i <= n; ++i)
            {
                double v1 = c(2*n - i,n) + (n + 1)*a + (n - i)*b;
                double v2 = c(2*n - i,n) + (n + 1)*b + (n - i)*a;
                ans += i * (exp(v1) + exp(v2));
            }
        }
        printf("Case %d: %.6Lf\n", ++kase, ans);
    }
    return 0;
}

