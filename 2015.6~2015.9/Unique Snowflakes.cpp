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
				mp[num[i]] = i + 1; //�ҵ��±��Ǵ�0��ʼ����1��Ϊ����Ϊ�����ʼλ��Ϊ0�����Ĭ�ϵĳ�ʼֵ�ظ��� 
				++temp;
			}
			else
			{
				i = k - 1;          //����������ص���Ӧ��ͬ���ֵ��ʱ��Ҫ��1 
				mp.clear();        //�ǵ���� 
				ans = max(ans, temp);
				temp = 0;          //�ǵø���Ϊ0 
			}
		}
		ans = max(ans, temp);
		printf("%d\n", ans);
	}
	return 0;
}

