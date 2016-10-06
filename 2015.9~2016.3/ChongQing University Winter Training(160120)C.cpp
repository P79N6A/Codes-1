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
const int MAXN = 1e5 + 111;

int a[MAXN];

int main()
{
    bool flag = 1;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int f = a[k];
    for (int j = k; j <= n; ++j) if (f != a[j]) flag = 0;
    if (flag) {
        for (int i = k; i >= 1; --i) {
            if (f == a[i]) k = i;
            else break;
        }
    }
    if (flag) cout << k - 1 << '\n';
    else cout << -1 << '\n';
    return 0;
}
