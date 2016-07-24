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
const int MAXN = 1111;

int h[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int L = h[i], R = h[i];
        int l = 0, r = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (h[j] <= L) {
                ++l;
                L = h[j];
            }
            else break;
        }
        for (int j = i + 1; j < n; ++j) {
            if (h[j] <= R) {
                ++r;
                R = h[j];
            }
            else break;
        }
        ans = max(ans, l + r + 1);
    }
    cout << ans << '\n';
    return 0;
}
