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
const int MAXN = 1e6 + 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0, mx = 0, len = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > mx) {
            mx = a[i];
            ++len;
        }
        else {
            ans = max(ans, len);
            mx = a[i];
            len = 1;
        }
    }
    ans = max(ans, len);
    cout << ans << '\n';
    return 0;
}
