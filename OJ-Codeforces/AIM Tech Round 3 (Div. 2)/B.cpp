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

int x[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, a;
    while (~scanf("%d%d", &n, &a)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }
        sort(x, x + n);
        int ans = INF;
        if (n == 1) ans = 0;
        else if (a < x[0]) ans = x[n - 2] - a;
        else if (a > x[n - 1]) ans = a - x[1];
        else {
            if (a > x[n - 2]) ans = min(ans, a - x[0]);
            else ans = min(ans, x[n - 2] - x[0] + min(x[n - 2] - a, a - x[0]));
            if (a < x[1]) ans = min(ans, x[n - 1] - a);
            else ans = min(ans, x[n - 1] - x[1] + min(a - x[1], x[n - 1] - a));
        }
        printf("%d\n", ans);
    }
    return 0;
}
