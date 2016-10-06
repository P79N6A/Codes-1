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
	string s1,s, s2;
	while (cin >> s1 && s1 != "ENDOFINPUT")
	{
		getchar();
		getline(cin,s,'\n');
		for (int i = 0; i < s.length(); ++i)
		{
			if ((s[i] >= 'A' && s[i] <= 'Z'))
			{
				s[i] -= 5; 
				if (s[i] < 'A')
					s[i] = 'Z' + s[i] - 'A' + 1;
			}
		}
		for (int i = 0; i < s.length(); ++i)
			cout << s[i];
		cout << '\n';
		cin >> s2;
	}
	return 0;
}

