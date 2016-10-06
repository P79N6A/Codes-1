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
		string mi = s;
		int len = s.length();
		s += s;
		for (int i = 0; i < len; ++i)
		{
			string nx = s.substr(i, len);
			//cout << nx << endl;
			if (mi > nx)
				mi = nx;
		}
		cout << mi << '\n';
	}
	return 0;
}

