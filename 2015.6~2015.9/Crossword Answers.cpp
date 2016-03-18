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

string s[15];
bool flag[15][15];
int mp[15][15];

int main()
{
//	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int r, c;
	int cnt = 0;
	while (cin >> r >> c && r && c)
	{
		memset(mp, 0, sizeof mp);
		for (int i = 0; i < r; ++i)
		{
			cin >> s[i];
			//cout << s[i] << endl;
		}
		int num = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			{
				if (s[i][j] != '*' && (i - 1 < 0 || j - 1 < 0 || s[i - 1][j] == '*' || s[i][j - 1] == '*'))
				{
					mp[i][j] = ++num;
				}
			}
		if (cnt != 0)
			cout << '\n';
		cout << "puzzle #" << ++cnt << ":\n";
		cout << "Across\n";
		memset(flag, 0, sizeof flag);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			{
				if (mp[i][j] && !flag[i][j])
				{
					printf("%3d.", mp[i][j]);
					for (int k = 0; s[i][j + k] != '*' && j + k < c; ++k)
					{
						cout << s[i][j + k];
						flag[i][j + k] = 1;
					}
					cout << '\n';
				}
			}
		cout << "Down\n";
		memset(flag, 0, sizeof flag);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			{
				if (mp[i][j] && !flag[i][j])
				{
					printf("%3d.", mp[i][j]);
					for (int k = 0; s[i + k][j] != '*' && i + k < r; ++k)
					{
						cout << s[i + k][j];
						flag[i + k][j] = 1;
					}
					cout << '\n';
				}
			}
	}
	return 0;
}

