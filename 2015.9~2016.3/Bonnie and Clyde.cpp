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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int x[MAXN], w[MAXN], mx[MAXN], pos[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, d; scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &w[i]);
    mx[n - 1] = w[n - 1];
    pos[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        pos[i] = i;
        mx[i] = w[i];
        if (mx[i] < mx[i + 1]) {
            mx[i] = mx[i + 1];
            pos[i] = pos[i + 1];
        }
    }
    int ansl = -2, ansr = -2, ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(x, x + n, x[i] + d) - x;
        if (p >= n) continue;
        if (mx[p] + w[i] > ans) {
            ansl = i, ansr = pos[p], ans = mx[p] + w[i];
        }
    }
    printf("%d %d\n", ansl + 1, ansr + 1);
    return 0;
}
