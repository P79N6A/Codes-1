#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int num[40];

int main()
{
	string s;
	while( getline(cin, s) )
	{
		vector<int> v;  //���� 
		vector<int> ans; //����� 
		stringstream ss(s);
		int x;
		int cnt = 0;
		while(ss >> x)
		{
			num[cnt] = x;
			++cnt;
			v.push_back(x);
		}
		sort(num, num + cnt); //�Ÿ���Ȼ��ÿ�������ļ�����з�ת 
		for(int i = 0; i < v.size(); ++i)
		{
			if(i) cout << ' ';
			cout << v[i];
		}
		cout << '\n';
		for(int i = cnt - 1; i >= 0; --i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(v[j] == num[i])
				{
					if(j == 0) //������ļ�����ڵ�һ��λ�ã�һ�η�ת���ܰ���Ū���ײ� 
					{
						ans.push_back(v.size() - i);
						reverse(v.begin(),v.begin() + i + 1);
					}
					else //����Ҫ��ͬһ�����ת���� 
					{
						ans.push_back(v.size() - j);
						reverse(v.begin(),v.begin() + j + 1); 
						++i; //��Ϊ��û��ת���ײ������Բ��ܽ����¸�����ķ�ת 
					}
					break;
				}
			}
		}
		ans.push_back(0); //0��Ϊ���� 
		for(int i = 0; i < ans.size(); ++i)
		{
			if(i) cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}

