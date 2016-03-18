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

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int p1 = 0, p2 = 0;
		while (s1[p1] && s2[p2])
		{
			if (s1[p1] == s2[p2])
			{
				++p1, ++p2;
			}
			else
			{
				++p2;
			}
		}
		cout << (p1 == s1.length() ? "Yes": "No") << '\n';
	}
	return 0;
}

