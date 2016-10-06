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
		vector<int> v;  //存煎饼 
		vector<int> ans; //存操作 
		stringstream ss(s);
		int x;
		int cnt = 0;
		while(ss >> x)
		{
			num[cnt] = x;
			++cnt;
			v.push_back(x);
		}
		sort(num, num + cnt); //排个序，然后每次找最大的煎饼进行翻转 
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
					if(j == 0) //如果最大的煎饼就在第一个位置，一次翻转就能把它弄到底部 
					{
						ans.push_back(v.size() - i);
						reverse(v.begin(),v.begin() + i + 1);
					}
					else //否则要对同一煎饼翻转两次 
					{
						ans.push_back(v.size() - j);
						reverse(v.begin(),v.begin() + j + 1); 
						++i; //因为还没翻转到底部，所以不能进行下个煎饼的翻转 
					}
					break;
				}
			}
		}
		ans.push_back(0); //0作为结束 
		for(int i = 0; i < ans.size(); ++i)
		{
			if(i) cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}

