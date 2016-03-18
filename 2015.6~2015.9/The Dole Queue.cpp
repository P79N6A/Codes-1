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

const int MAXN = 1e6 + 111;

bool flag[20];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n, k, m;
	while (cin >> n >> k >> m && n != 0 && k != 0 && m != 0)
	{
		memset(flag, 0, sizeof flag);
		int num = 0;
		bool first = 1;
		int p1 = 1, p2 = n;
		
		while (1)
		{
			if (num == n)
				break;
			if (first)
			{
				first = 0;
			}
			else
			{
				printf(",");
			}
			int ans1, ans2;
			
			int cnt = 0;
			for (int i = p1; cnt != k; ++i)
			{
				if (i > n)
					i = 1;
				if (!flag[i])
				{
					++cnt;
					if (cnt == k)
					{
						ans1 = i;
						p1 = i;
					}
				}
			}
			
			cnt = 0;
			for (int i = p2; cnt != m; --i)
			{
				if (i < 1)
					i = n;
				if (!flag[i])
				{
					++cnt;
					if (cnt == m)
					{
						ans2 = i;
						p2 = i;
					}
				}
			}
			
			flag[ans1] = flag[ans2] = 1;
			
			if (ans1 == ans2)
			{
				printf("%3d", ans1);
				++num;
			}
			else
			{ 
				printf("%3d%3d", ans1, ans2);
				num += 2;
			}
		}
		cout << '\n';
	}
	return 0;
}

