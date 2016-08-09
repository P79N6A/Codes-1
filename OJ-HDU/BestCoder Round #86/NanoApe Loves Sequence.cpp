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

int a[MAXN];
int rmx[MAXN], lmx[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        memset(lmx, 0, sizeof lmx);
        memset(rmx, 0, sizeof rmx);
        for (int i = n - 2; i >= 0; --i) {
            rmx[i] = abs(a[i] - a[i + 1]);
            rmx[i] = max(rmx[i], rmx[i + 1]);
        }
        for (int i = 1; i < n; ++i) {
            lmx[i] = abs(a[i] - a[i - 1]);
            lmx[i] = max(lmx[i], lmx[i - 1]);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!i) {
                ans += rmx[1];
            }
            else if (i == n - 1) {
                ans += lmx[n - 2];
            }
            else {
                ans += max(lmx[i - 1], max(rmx[i + 1], abs(a[i - 1] - a[i + 1])));
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
