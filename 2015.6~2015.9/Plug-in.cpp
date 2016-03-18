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

const int MAXN = 2e5 + 111;

char s[MAXN];

int main()
{
	cin >> s[0];
	int len = 1;
	while (cin >> s[len])
	{
		if (s[len] == s[len - 1])
			len -= 1;
		else ++len;
	}
	s[len] = '\0';
	cout << s << endl;
	return 0;
}

