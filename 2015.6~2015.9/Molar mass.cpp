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
double ans;
string s;

bool is(char c)
{
	return (c > '0' && c <'9');
}

int calculate(int i, int len, double v)
{
	if (i + 2 < len && is(s[i + 2]))
	{
		if (is(s[i + 1]))
		{
			ans += (10 * (s[i + 1] - '0') + s[i + 2] - '0') * v;
			return 2;
		}
	}
	else if (i + 1 < len && is(s[i + 1]))
	{
		ans += (s[i + 1] - '0') * v;
		return 1;
	}
	ans += v;
	return 0;
}

int main()
{
	int t; cin >> t;
	while (t --)
	{
		s.clear();
		cin >> s;
		int len = s.length();
		ans = 0;
		for (int i = 0; i < len; ++i)
		{
			switch(s[i])
			{
				case 'C': i += calculate(i, len, 12.01); break;
				case 'H': i += calculate(i, len, 1.008); break;
				case 'O': i += calculate(i, len, 16.00); break;
				case 'N': i += calculate(i, len, 14.01); break;
			}
			//cout << ans << endl;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}

