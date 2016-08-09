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

ll a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, q, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        ll sum = 0;
        for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]), sum += a[i];
        ll x;
        for (int i = 0; i < m; ++i) {
            scanf("%I64d", &x);
            if (x > sum) putchar('1');
            else putchar('0');
        }
        putchar('\n');
    }
    return 0;
}
