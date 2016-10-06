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
const int MAXN = 5e3 + 111;

ll dp[2][MAXN];
int a[MAXN], b[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int cur = 0, v = 0;
    for (int i = 1; i <= n; ++i) {
        cur = v;
        v = !cur;
        dp[cur][1] = dp[v][1] + abs(a[i] - b[1]);
        for (int j = 2; j <= n; ++j) {
            dp[cur][j] = min(dp[cur][j - 1], dp[v][j] + abs(a[i] - b[j]));
        }
    }
    cout << dp[cur][n] << '\n';
    return 0;
}
