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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 103;

int mp[MAXN][MAXN], c[MAXN];
ll dp[MAXN][MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k)) {
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d", &c[i]);
    	}
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			scanf("%d", &mp[i][j]);
    		}
    	}
    	memset(dp, 0x3f, sizeof dp);
		if (c[1]) {
			dp[1][c[1]][1] = 0;
		}
		else {
			for (int j = 1; j <= m; ++j) {
				dp[1][j][1] = mp[1][j];
			}
		}
    	for (int i = 2; i <= n; ++i) {
    		if (c[i]) {
    			for (int l = 1; l <= k; ++l) {
    				for (int j = 1; j <= m; ++j) {
    					if (c[i] == j) dp[i][c[i]][l] = min(dp[i][c[i]][l], dp[i - 1][j][l]);
    					else dp[i][c[i]][l] = min(dp[i][c[i]][l], dp[i - 1][j][l - 1]);
    				}
    			}
    		}
    		else {
    			for (int l = 1; l <= k; ++l) {
	    			for (int cc = 1; cc <= m; ++cc) {
		    			for (int j = 1; j <= m; ++j) {
	    					if (cc == j) dp[i][cc][l] = min(dp[i][cc][l], dp[i - 1][j][l] + mp[i][cc]);
	    					else dp[i][cc][l] = min(dp[i][cc][l], dp[i - 1][j][l - 1] + mp[i][cc]);
		    			}
	    			}
    			}
    		}
    	}
    	ll ans = dp[0][0][0];
    	for (int i = 1; i <= m; ++i) ans = min(ans, dp[n][i][k]);
    	if (ans == dp[0][0][0]) puts("-1");
    	else cout << ans << '\n';
    }
    return 0;
}