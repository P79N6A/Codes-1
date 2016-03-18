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

const int MAXN = 5e5 + 111;

struct S{
	int a, b;
	bool operator < (const S& t)const
	{
		if (a != t.a)
			return a < t.a;
		else return b < t.b;
	}
	bool operator == (const S& t)const
	{
		return (a == t.a && b == t.b);
	}
}s[2][MAXN];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) && n)
	{
		int x, y;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &x, &y);
			s[0][i].a = x, s[0][i].b = y;
			s[1][i].a = y, s[1][i].b = x;
		}
		sort(s[0], s[0] + n);
		sort(s[1], s[1] + n);
		bool flag = 1;
		for (int i = 0; i < n; ++i)
		{
			if (s[0][i] == s[1][i])
			{
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}

