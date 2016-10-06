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
int num[20];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int t; cin >> t;
	while (t --)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", num + i);
		}
		bool flag = 0;
		for (int i = 0; i < 1001; ++i)
		{
			bool flag2 = 1;
			for (int j = 0; j < n; ++j)
			{
				//cout << num[j] << ' ';
				if (num[j] != 0)
				{
					flag2 = 0;
				}
			}
			int t = num[0];
			for (int j = 0; j < n - 1; ++j)
			{
				num[j] = abs(num[j] - num[j + 1]); 
			}
			num[n - 1] = abs(num[n - 1] - t);
			//cout <<'\n';
			//system("pause");
			if (flag2)
			{
				flag = 1;
				break;
			}
		}
		printf("%s\n", (flag? "ZERO":"LOOP")); 
	}
	return 0;
}

