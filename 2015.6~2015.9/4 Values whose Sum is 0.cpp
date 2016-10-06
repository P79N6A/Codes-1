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
const int MAXN = 4e3 + 11;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int sum1[MAXN*MAXN], sum2[MAXN*MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t; scanf("%d", &t);
	for(int kase = 0; kase < t; ++kase)
	{
		int n; scanf("%d", &n);
		for( int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
		}
		int ans = 0;
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				sum1[cnt++] = a[i] + b[j];
			}
		cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				sum2[cnt++] = -c[i] - d[j];
			}
		sort(sum2, sum2 + cnt);
		for(int i = 0; i < cnt; ++i)
		{
			ans += upper_bound(sum2, sum2 + cnt, sum1[i]) - lower_bound(sum2, sum2 + cnt, sum1[i]) ;
		}
		if(kase) printf("\n");
		printf("%d\n", ans);
	}
	return 0;
}

