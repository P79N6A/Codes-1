#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;

const int MAXN = 1e6 + 111;

int h1[26];
bool flag[26];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n;
	while (cin >> n && n != -1)
	{
		memset(h1, 0, sizeof h1);
		memset(flag, 0, sizeof flag);
		string s1, s2;
		cin >> s1 >> s2;
		int len1 = s1.length(), len2 = s2.length();
		for (int i = 0; i < len1; ++i)
			++h1[s1[i] - 'a'];
		int ans = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (h1[i])
				++ans;
		}
		
		int wrong = 0, right = 0;
		for (int i = 0; i < len2; ++i)
		{
			if (h1[s2[i] - 'a'] && !flag[s2[i] - 'a'])
			{
				++right;
				if (right == ans)
					break;
				flag[s2[i] - 'a'] = 1;
			}
			else if (!flag[s2[i] - 'a'])
			{
				flag[s2[i] - 'a'] = 1;
				++wrong;
				if (wrong == 7)
					break;
			}
		}	
		
		cout << "Round " << n << '\n';
		if (right == ans)
			cout << "You win.\n";
		else if (wrong == 7)
			cout << "You lose.\n";
		else cout << "You chickened out.\n";
	}
	return 0;
}

