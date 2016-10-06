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

int sum(int a)
{
	int res = 0;
	while (a)
	{
		res += a % 10;
		a /= 10;
	}
	return res;
}

int main()
{
	int t; cin >> t;
	while (t --)
	{
		int num;
		cin >> num;
		int test = num;
		int len = 0;
		while (test)
		{
			test /= 10;
			++len;
		}
		bool flag = 1;
		for (int i = num - len * 9; i < num; ++i)
		{
			if (i + sum(i) == num)
			{
				cout << i << '\n';
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << 0 << '\n';
	}
	return 0;
}

