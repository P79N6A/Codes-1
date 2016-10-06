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
int num[MAXN], dp[MAXN];
int pos[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i], dp[i] = 1, pos[num[i]] = i;

    int ans = 1;
    for (int i = n - 1; i >= 0; --i) {
        int v = num[i] + 1;
        if (pos[v] > i) {
            dp[i] += dp[pos[v]];
        }
        ans = max(ans, dp[i]);
    }

    cout << n - ans << '\n';
    return 0;
}
