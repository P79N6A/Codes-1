#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN = 1e5 + 6e4;

map<string, bool> mp; //是否在字典中 
string s[MAXN];

int main()
{
//	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int cnt = 0;
	while (cin >> s[cnt])
	{
		mp[s[cnt]] = 1;
		++cnt;
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < s[i].length(); ++j) //考察所有组合 
		{
			string t1, t2;
			t1 = s[i].substr(0, j);
			t2 = s[i].substr(j);
			if (mp[t1] && mp[t2])
			{
				cout << s[i] << '\n';
				break;
			}
		}
	}
	return 0;
}

