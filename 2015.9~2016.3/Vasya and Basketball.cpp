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

int t1[MAXN], t2[MAXN];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t1[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> t2[i];
    sort(t1, t1 + n); sort(t2, t2 + m);

    int l = 3 * n, r = 3 * m, mx = l - r;
    for (int i = 0; i < n + m; ++i) {
        int x;
        if (i < n) x = t1[i];
        else x = t2[i - n];
        int x1 = upper_bound(t1, t1 + n, x) - t1;
        int x2 = upper_bound(t2, t2 + m, x) - t2;
        int templ = 3 * n - x1;
        int tempr = 3 * m - x2;
        int temp = templ - tempr;
        if (temp > mx || (temp == mx) && l < templ) {
            mx = temp; l = templ; r = tempr;
        }
    }
    cout << l << ":" << r << '\n';
    return 0;
}
