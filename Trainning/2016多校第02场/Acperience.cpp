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
const int MAXN = 1e5 + 111;

ll w[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    ll n;
    while (t --) {
        scanf("%lld", &n);
        ll sum = 0;
        ll up = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &w[i]);
            w[i] = labs(w[i]);
            sum += w[i] * w[i];
            up += w[i];
        }
        up *= up;
        sum = sum * n - up;
        ll div = __gcd(sum, n);
        printf("%lld/%lld\n", sum / div, n / div);
    }
    return 0;
}
