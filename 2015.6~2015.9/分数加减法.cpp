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

int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	int a, b, c, d;
	string s;
	while (cin >> s)
	{
		a = s[0] - '0', b = s[2] - '0', c = s[4] - '0', d = s[6] - '0';
		if (s[3] == '+')
		{
			int e = a * d + b * c, f = b * d;
			int up = e / gcd(e, f), down = f / gcd(e,f);
			if (up % down == 0)
				cout << up / down << '\n';
			else cout << up << '/' << down << '\n';
		}
		else
		{
			int e = a * d - b * c, f = b * d;
			int add = 1;
			if (e < 0)
				add = -1;
			int up = abs(e / gcd(e, f)), down = abs(f / gcd(e,f));
			if (up % down == 0)
				cout << add * up / down << '\n';
			else cout << add * up << '/' << down << '\n';
		}
	}
	return 0;
}

