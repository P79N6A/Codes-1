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
const int MAXN = 1e6 + 111;

int a[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, h, k, x;
    ios_base::sync_with_stdio(0);
    cin >> n >> h >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    double tol = 0;
    for (int i = 0; i < n - 1; ++i) {
        tol += a[i];
        if (tol >= (h - a[i + 1]))
            x = ceil((tol - (h - a[i + 1])) / k);
        else x = 0;
        ans += x;
        tol = max((ll)tol - x * k, (ll)0);
    }
    tol += a[n - 1];
    ans += ceil(tol / k);
    cout << ans << '\n';
    return 0;
}
