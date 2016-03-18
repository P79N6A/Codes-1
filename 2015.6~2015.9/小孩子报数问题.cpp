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

string name[70];
bool flag[70];

int main()
{
	int n; cin >> n;
	int left = n;
	for (int i = 0; i < n; ++i)
	{
		cin >> name[i];
	}
	int w, s; scanf("%d,%d", &w, &s);
	s = s % n;
	int len = 0;
	int num = n;
	while (num)
	{
		bool go = 1;
		for (int i = w - 1; i < n; ++i)
		{
			if (!flag[i])
			{
				++len;
				if(len == s)
				{
					flag[i] = 1;
					cout << name[i] << '\n';
					w = i + 1;
					len = 0;
					break;
				}
			}
			if (i == n - 1)
				i = -1;
		}
		--num;
	}
	return 0;
}

