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
const int N = 100000;
int a[20], b[20], c[20]; 

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, kase = 0;
	while( cin >> n && n )
	{
		for( int i = 0 ; i < n ; ++i )
			cin >> a[i] >> b[i] >> c[i];
		int cnt = 0, t;
		for(t = 1; t < N; ++t)
		{
			cnt = 0;
			for( int i = 0 ; i < n ; ++i )
				if( c[i] <= a[i])
					++cnt;
			if(cnt == n) break;
			for( int i = 0 ; i < n ; ++i )
			{
				if(c[i] == a[i] + b[i] || (c[i] == a[i] && n - cnt <= cnt))
					c[i] = 0;
				++c[i];
			}
		}
		if(t == N) t = -1;
		cout << "Case " << ++kase << ": " << t << '\n';
	}
	return 0;
}

