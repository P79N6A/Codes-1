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
typedef long long ll;
ll num[22];
int nn[MAXN];


int main()
{
#ifdef LOCAL
//	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nn[i];
		nn[i] += 10;
		++num[nn[i]];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (nn[i] == 10 && num[nn[i]])
		{
			--num[nn[i]];
			ans += num[nn[i]];
		}
		else if (num[nn[i]])
		{
			ans += num[20 - nn[i]];
			--num[nn[i]];
		}
	}
	cout << ans << '\n';
	return 0;
}

