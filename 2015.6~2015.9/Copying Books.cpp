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
typedef long long ll;
const int MAXN = 5e2 + 111;
ll p[MAXN], t, m, k;
bool vis[MAXN]; 

ll ans(ll mid)
{
	int cnt = 1; //至少都会分给一个人 
	ll sum = 0;
	for( int i = 0; i < m; ++i )
	{
		if(sum + p[i] <= mid) sum += p[i];
		else
		{
			++cnt;
			sum = p[i];
		}
	}
	return cnt;
}

int main()
{
	cin >> t;
	while( t --)
	{
		cin >> m >> k;
		ll sum = 0, mx = 0;
		for( int i = 0; i < m; ++i) {cin >> p[i]; mx = max(mx, p[i]); sum += p[i];}
		ll l = mx, r = sum;
		while( l < r )
		{
			ll mid = l + (r - l) / 2;
			if(ans(mid) <= k) r = mid;
			else l = mid + 1;
		}
		sum = 0;
		memset(vis, 0, sizeof vis);
		int lef = k;
		for(int i = m - 1; i >= 0; --i)
		{
			if( sum + p[i] > l || i + 1 < lef )
			{
				--lef;
				sum = p[i];
				vis[i] = 1;
			}
			else sum += p[i];
		}
		for(int i = 0; i < m; ++i)
		{
			if(i) cout << ' ';
			cout << p[i];
			if(vis[i])
				cout << " /";
		}
		cout << '\n';
	}
	return 0;
}

