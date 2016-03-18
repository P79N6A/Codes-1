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
	int t; cin >> t;
	while (t --)
	{
		string s;
		cin >> s;
		int len = s.length();
		for (int i = 1; i <= len; ++i)
		{
			if (len % i == 0)
			{
				bool flag = 1;
				string p = s.substr(0, i);
				for (int j = 0; j < len; j += i)
				{
					string pp = s.substr(j, i);
					if (pp != p)
					{
						flag = 0;
						break;
					}
				}
				if (flag)
				{
					cout << i << '\n';
					break;
				}
			}
		}
		if (t != 0)
			cout << '\n';
	}
	return 0;
}

