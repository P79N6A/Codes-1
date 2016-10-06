#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;

const int MAXN = 1e6 + 111;
set<string> s;

bool cmp(string a, string b)
{
	return a < b;
}

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string ss;
	while (getline(cin, ss))
	{
		for (int i = 0; i < ss.length(); ++i)
		{
			string word;
			while (isalpha(ss[i]))
			{
				word += tolower(ss[i]);
				++i;
			}
			if (!word.empty())
				s.insert(word);
		}
	} 
	//sort(s.begin(),s.end());
	for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << '\n';
	}
	return 0;
}

