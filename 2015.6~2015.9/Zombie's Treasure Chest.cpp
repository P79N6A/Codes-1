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
const int MAXN = 1e6 + 111;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t; cin >> t;
	long long ans, n, s, v, s2, v2;
	for( int kase = 1 ; kase <= t ; ++kase )
	{
		cin >> n >> s >> v >> s2 >> v2;
		int lef = n / s, lef2 = n / s2;
		ans = 0;
		if( lef <= 1e6 && lef2 <= 1e6 )
		{
			if( lef <= lef2 )
			{
				for( int i = 0 ; i <= lef ; ++i)
					ans = max( ans , i * v + (n - i * s) / s2 * v2 );
			}
			else
			{
				for( int i = 0 ; i <= lef2 ; ++i)
					ans = max( ans , i * v2 + (n - i * s2) / s * v );
			}
		}
		else
		{
			if( s * v2 <= s2 * v )
			{
				for( int i = 0 ; i < s ; ++i)
					ans = max( ans , i * v2 + (n - i * s2) / s * v ); 
			}
			else
			{
				for( int i = 0 ; i < s2 ; ++i)
					ans = max( ans , i * v + (n - i * s) / s2 * v2 );
			}
		}
		cout << "Case #" << kase << ": " << ans << '\n';
	}
	return 0;
}

