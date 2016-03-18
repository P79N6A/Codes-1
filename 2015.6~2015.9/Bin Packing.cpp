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
int len[MAXN];
bool vis[MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n, cap; cin >> t;
	for( int kase = 0; kase < t; ++kase)
	{
		memset(vis, 0,sizeof vis);
		cin >> n >> cap;
		for( int i = 0; i < n; ++i) cin >> len[i];
		sort(len, len + n);
		int ans = 0;
		for( int i = n - 1; i >= 0; --i )
		{
			if(!vis[i])
			{
				++ans;
				int lef = cap - len[i];
				vis[i] = 1;
				if( lef < len[0] ) goto label;
				int p = min(int(upper_bound(len, len + n, lef) - len), n - 1);
				//cout << lef << ',' << p << endl;
				for(int j = p; j >= 0; --j)
				{
					if(!vis[j] && len[j] <= lef)
					{
						vis[j] = 1;
						break;
					}
				}
			}
			label:;
		}
		if(kase) cout << '\n';
		cout << ans << '\n';
	}
	return 0;
}

