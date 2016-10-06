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
const int MAXN = 5e3 + 111;
typedef long long ll;

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while(scanf("%d", &n) && n )
	{
		priority_queue<ll, vector<ll>, greater<ll> > pq;
		ll x;
		for (int i = 0; i <n; ++i)
		{
			scanf("%lld", &x);
			pq.push(x); 
		}
		ll sum = 0;
		ll cost = 0;
		while(!pq.empty())
		{
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			sum += a + b;
			if(pq.empty())
				break;
			else pq.push(a + b);
		}
		printf("%lld\n", sum);
	}
	return 0;
}

