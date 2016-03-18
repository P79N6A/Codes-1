#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	string s;
	while (cin >> s)
	{
		int a = 0, b = 0;
		bool flag = 0;
		for (int i = 0; s[i]; ++i)
		{
			if (s[i] == '4')
			{ 
				++a;
				flag = 1;
			}
			if (s[i] == '7')
			{
				++b;
				flag = 1;
			}
		}
		if (flag)
		{
		if (a >= b)
			cout << 4 << '\n';
		else cout << 7 << '\n';
		}
		else cout << -1 << '\n';
	}
	return 0;
}

