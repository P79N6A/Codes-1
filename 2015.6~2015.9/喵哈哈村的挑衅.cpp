#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
int dp[30][30][30][30], sa[30], sb[30], a[30], b[30];

int dfs(int x1, int y1,int x2,int y2)
{
    if(dp[x1][y1][x2][y2] >= 0) return dp[x1][y1][x2][y2];
    int sum = 0;
    int ret = 0;
    if(x1 <= y1) sum += sa[y1] - sa[x1 - 1];
    if(x2 <= y2) sum += sb[y2] - sb[x2 - 1];
    if(x1 <= y1)
        ret = max(ret, sum - min(dfs(x1 + 1, y1, x2, y2), dfs(x1, y1 - 1, x2, y2)));
    if(x2 <= y2)
        ret = max(ret, sum - min(dfs(x1, y1, x2 + 1, y2), dfs(x1, y1, x2, y2 - 1)));
    return dp[x1][y1][x2][y2] = ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while(cin >> n)
	{
	    memset(sa, 0, sizeof sa);
	    memset(sb, 0, sizeof sb);
	    memset(dp, -1, sizeof dp);
	    for(int i = 1; i <= n; ++i) cin >> a[i];
	    for(int i = 1; i <= n; ++i) cin >> b[i];
	    for(int i = 1; i <= n; ++i)
	    {
	        sa[i] = sa[i - 1] + a[i];
            sb[i] = sb[i - 1] + b[i];
        }
        cout << dfs(1, n, 1, n) << '\n';
    }
	return 0;
}


