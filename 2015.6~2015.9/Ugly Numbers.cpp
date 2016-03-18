#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;

const int MAXN = 1e4 + 111;
typedef long long ll;

int num[3] = {2, 3, 5};

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	set<ll> s;
	s.insert(1);
	int cnt = 0;
	ll ans = 0;
	while (!s.empty())
	{
		++cnt;
		ll now = *s.begin();
		for (int i = 0; i < 3; ++i)
		{
			s.insert((ll)num[i] * now);
		}
		s.erase(now);
		if (cnt == 1500)
		{
			ans = now;
			break;
		}
	}
	cout << "The 1500'th ugly number is " << ans << ".\n";
	return 0;
}

