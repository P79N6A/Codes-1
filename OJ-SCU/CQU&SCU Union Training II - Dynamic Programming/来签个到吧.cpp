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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 6e4 + 111;

int a[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int first = 1;
        int add = a[1];
        for (int i = (a[0] == 0) + 1; i < n; ++i) {
            if (first) {
                add = __gcd(a[i], a[i - 1]);
                first = 0;
            }
            else {
                add = __gcd(add, a[i]);
            }
        }
        int r = a[n - 1] / add + (a[0] == 0);
        double mul = add;
        double base = r;
        double ans = 0;
        for (int i = 1; i <= r; ++i) {
            ans += base / i;
        }
        printf("%d\n", int(ans + base - n));
    }
    return 0;
}
