#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 1e6 + 111;
int num[MAXN];

int main()
{
	int t; scanf("%d", &t);
	while(t --)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mp;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", num + i);
		}
		int ans = 0, temp = 0;
		for(int i = 0; i < n; ++i)
		{
			//cout << num[i] << "===" << temp << endl;
			int k = mp[num[i]];
			if(!k)
			{
				mp[num[i]] = i + 1; //我的下标是从0开始，加1是为了因为如果初始位置为0，会和默认的初始值重复了 
				++temp;
			}
			else
			{
				i = k - 1;          //所以在这里回到对应相同数字点的时候要减1 
				mp.clear();        //记得清空 
				ans = max(ans, temp);
				temp = 0;          //记得更新为0 
			}
		}
		ans = max(ans, temp);
		printf("%d\n", ans);
	}
	return 0;
}

