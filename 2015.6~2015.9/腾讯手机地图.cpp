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

const double PI = acos(-1);

int r[366];

int main()
{
	int t; scanf("%d", &t);
	while (t --)
	{
		memset(r, 0, sizeof r);
		int n; scanf("%d", &n);
		int a, b, c;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			b += 90, c += 90;
			for (int j = b; j < c; ++j)
			{
				if (a > r[j])
					r[j] = a;
			}
		}
		double ans = 0;
		for (int i = 0; i < 360; ++i)
		{
            ans += (double)r[i] * (double)r[i] * PI / 360.0;
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}

