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
const int MAXN = 1e5 + 111;
ll num[MAXN];
ll sum;

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%lld", num + i);
		sum = 0;
		for(int i = 0; i < n - 1; ++i)
		{
			sum += abs(num[i]);
			num[i + 1] += num[i];
		}
		cout << sum << '\n';
	}
	return 0;
}

