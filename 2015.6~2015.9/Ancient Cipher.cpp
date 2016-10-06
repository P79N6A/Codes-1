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

int hash1[26], hash2[26], hash3[26];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		memset(hash1, 0, sizeof hash1);
		memset(hash2, 0, sizeof hash2);
		for (int i = 0; i < s1.length(); ++i)
		{
			++hash1[s1[i] - 'A'];
		}
		for (int i = 0; i < s2.length(); ++i)
			++hash2[s2[i] - 'A'];
		sort(hash1, hash1 + 26);
		sort(hash2, hash2 + 26);
		bool flag = 1;
		for (int i = 0; i < 26; ++i)
		{
			if (hash1[i] != hash2[i])
			{
				flag = 0;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}

