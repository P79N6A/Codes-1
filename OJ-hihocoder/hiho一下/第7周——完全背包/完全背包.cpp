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

int dp[MAXN];
int need[666], val[666];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> need[i] >> val[i];
    for (int i = 0; i < n; ++i) {
        for (int j = need[i]; j <= m; ++j)
            dp[j] = max(dp[j], dp[j - need[i]] + val[i]);
    }
    cout << dp[m] << '\n';
    return 0;
}
