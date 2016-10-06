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
const int MAXN = 511;

bool dp[MAXN][MAXN][MAXN];
int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= k; ++l) {
                if (l >= a[i]) {
                    dp[i][l][j] |= dp[i - 1][l - a[i]][j];
                    if (j >= a[i])
                        dp[i][l][j] |= dp[i - 1][l - a[i]][j - a[i]];
                }
                dp[i][l][j] |= dp[i - 1][l][j];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; ++i) {
        if (dp[n][k][i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}
