#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 511;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + a[i + 1] >= k) continue;
        else {
            int add = k - (a[i] + a[i + 1]);
            ans += add;
            a[i + 1] += add;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    return 0;
}
