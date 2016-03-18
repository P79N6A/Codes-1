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
const int MAXN = 1e3 + 111;

bool ok[MAXN];

int main()
{
    int ans = 0;
    int n, m;
    cin >> n >> m;
    int a, b;
    while (m --) {
        cin >> a >> b;
        ok[a] = ok[b] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!ok[i]) {
            ans = i;
            break;
        }
    }
    cout << n - 1 << '\n';
    for (int i = 1; i <= n; ++i) {
        if (i == ans) continue;
        cout << i << ' ' << ans << '\n';
    }
    return 0;
}
