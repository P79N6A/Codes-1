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
const int MAXN = 111;

int a[MAXN];

int main()
{
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 1;
    int i = 0;
    for (; i < n; ++i) {
        if (a[i] == 1) break;
    }
    if (i == n) ans = 0;

    ll sum = 1;
    for (; i < n; ++i) {
        if (a[i] == 0) {
            ++sum;
        }
        else {
            ans *= sum;
            sum = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
