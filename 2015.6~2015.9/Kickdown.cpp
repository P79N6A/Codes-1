#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int MAXN = 1e6 + 111;

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string s, s2;
	while (cin >> s >> s2)
	{
		if (s.size() < s2.size())
			swap(s, s2);
		int len = s2.size();
		int len2 = s.size();
		int j;
		int ans = 1000;
		
		
		for (int i = 0; s[i]; ++i)
		{
			bool flag = 1;
			for (j = 0; j < s.size() - i && j < len; ++j)
			{
				if (s[i + j] - '0' + s2[j] > '3')
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				ans = min(ans, len2 + len - j);
				break;
			}
			if (i == s.size() - 1)
			{
				ans = min(ans, len2 + len);
			}
		}
		
		for (int i = 0; i < len / 2; ++i)
			swap(s2[i], s2[len - i - 1]);
		for (int j = 0; j < len2 / 2; ++j)
			swap(s[j], s[len2 - j - 1]);
		for (int i = 0; s[i]; ++i)
		{
			bool flag = 1;
			for (j = 0; j < s.size() - i && j < len; ++j)
			{
				if (s[i + j] - '0' + s2[j] > '3')
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				ans = min(ans, len2 + len - j);
				break;
			}
			if (i == s.size() - 1)
			{
				ans = min(ans, len2 + len);
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}

