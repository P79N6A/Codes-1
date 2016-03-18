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
	string s;
	while (getline(cin, s, '\n'))
	{
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u')
			{
				cout << "we";
				i += 2;
			}
			else cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}

