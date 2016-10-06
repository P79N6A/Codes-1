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
	while (cin >> s)
	{
		cout << s << " -- is ";
		int len = s.length();
		bool flag1 = 1;
		for (int i = 0; i < len / 2; ++i)
		{
			if (s[i] != s[len - i - 1])
				flag1 = 0;
		}
		string s2 = s;
		bool flag2 = 1;
		for (int i = 0; i < len; ++i)
		{
			switch(s[i])
			{
				case 'E': s[i] = '3'; break;
				case 'J': s[i] = 'L'; break;
				case 'L': s[i] = 'J'; break;
				case 'O': s[i] = 'O'; break;
				case 'S': s[i] = '2'; break;
				case 'Z': s[i] = '5'; break;
				case '2': s[i] = 'S'; break;
				case '3': s[i] = 'E'; break;
				case '5': s[i] = 'Z'; break;
				case 'A': break;
				case 'H': break;
				case 'I': break;
				case 'M': break;
				case 'T': break;
				case 'U': break;
				case 'V': break;
				case 'W': break;
				case 'X': break;
				case 'Y': break;
				case '1': break;
				case '8': break;
				default:
					s[i] = ' ';
					break;
			}
			if (s[i] != s2[len - i - 1])
			{
				flag2 = 0;
				break;
			}
		}
		if (flag1 && flag2)
		{
			cout << "a mirrored palindrome.\n\n";
		}
		else if (flag1)
		{
			cout << "a regular palindrome.\n\n";
		}
		else if (flag2)
		{
			cout << "a mirrored string.\n\n";
		}
		else cout << "not a palindrome.\n\n";
	}
	return 0;
}

