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
const int MAXN = 2e5 + 111;

int a[MAXN];
bool is[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int n, m, k;
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        memset(is, 0, sizeof is);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] >= m) is[i] = 1;
        }
        ll ans = 0;
        int p = 0, num = 0;
        for (int i = 0; i < n; ++i) {
            while (p < n && num != k) {
                if (is[p]) {
                    ++num;
                }
                ++p;
            }
            if (num == k) {
                ans += n - p + 1;
            }
            if (is[i]) --num;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
