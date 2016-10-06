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
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int mi = 0, mx = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int miv = a[0], mxv = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > mxv) {
            mxv = a[i];
            mx = i;
        }
        if (a[i] < miv) {
            miv = a[i];
            mi = i;
        }
    }
    if (mi > mx) swap(mi, mx);
    int ans = max(n - 1 - mi, mx);
    cout << ans << '\n';
    return 0;
}
