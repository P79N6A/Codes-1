#include<iostream>
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
const int MAXN = 1e5 + 111;
bool vis[MAXN];
char dp[MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int d, n;
	while( cin >> d >> n && (d || n) )
	{
		string s, temp;
		memset(vis, 0, sizeof vis);
		cin >> s;
		dp[d - 1] = s[d - 1];
		for(int i = d - 2; i >= 0; --i)
		{
			dp[i] = max(dp[i + 1], s[i]);
		}
		string ans;
		int p = -1;
		for(int i = 0; i < d - n; ++i)
		{
			char mx = '0';
			for(int j = p + 1; j <= n + i; ++j)
			{
				if(!vis[j] && mx < s[j])
				{
					mx = s[j];
					p = j;
				//	cout << j << ',' << dp[j] << endl;
					if(s[j] >= dp[j]) break;
				}
			}
			vis[p] = 1;
			ans += mx;
		}
		cout << ans << '\n';
	}
	return 0;
}

