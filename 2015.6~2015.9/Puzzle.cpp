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
//	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int cnt = 0;
	string s[5];
	while (1)
	{
		for (int i = 0; i < 5; ++i)
		{
			getline(cin, s[i]);
			//cout << s[i] <<endl;
		}
		if (s[0] == "Z")
			break;
		int x, y;
		bool flag = 0;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				if (s[i][j] == ' ')
				{
					x = i, y = j;
					break;
				}
		char c;
		while (scanf("%c", &c) && c != '0')
		{
			if (c == 'B')
			{
				if (x + 1 >= 5)
				{
					flag = 1;
				}
				else{
					swap(s[x][y], s[x + 1][y]);
					++x;
				}
			}
			else if (c == 'A')
			{
				if (x - 1 < 0)
				{
					flag = 1;
				}
				else{
				swap(s[x][y], s[x - 1][y]);
				--x;
			}
			}
			else if (c == 'L')
			{
				if (y - 1 < 0)
				{
					flag = 1;
				}
				else{
				swap(s[x][y - 1], s[x][y]);
				--y;
			}
			}
			else if (c == 'R')
			{
				if (y + 1 >= 5)
				{
					flag = 1;
				}
				else{
				swap(s[x][y + 1], s[x][y]);
				++y;
			}
			}
		}
		getchar();
		if (cnt != 0)
			cout << '\n';
		cout << "Puzzle #" << ++cnt << ":\n";
		if (flag)
		{
			cout << "This puzzle has no final configuration.\n";
			continue;
		}
		for (int i = 0; i < 5; ++i, cout << '\n')
			for (int j = 0; j < 5; ++j)
			{
				if (j != 0)
					cout << ' ';
				cout << s[i][j];
			}
	}
	return 0;
}

