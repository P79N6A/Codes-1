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
const int MAXN = 1e5 + 111;

int x[MAXN];

int ok(int len, int n) {
    int ret = 0, i = 0;
    while (i < n) {
        i = upper_bound(x + i, x + n, x[i] + len - 1) - x;
        ++ret;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, k, n;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        int l = 1, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid, n) <= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
