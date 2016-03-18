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

const int MAXN = 1e6 + 111;

bool flag[10][10][10][10];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n, m;
	int cnt = 0;
	while (cin >> n >> m)
	{
		memset(flag, 0, sizeof flag);
		char op;
		int x, y;
		for (int i = 0; i < m; ++i)
		{
			cin >> op >> x >> y;
			if (op == 'H')
			{
				flag[x][y][x][y + 1] = 1;
			}
			else
			{
				flag[y][x][y + 1][x] = 1;
			}
		}
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (flag[j][i][j + 1][i])
				{
					int k = j + 1;
					while(k + 1 <= n && flag[k][i][k + 1][i])
					{
						++k;
						flag[j][i][k][i] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (flag[i][j][i][j + 1])
				{
					int k = j + 1;
					while (k + 1 <= n && flag[i][k][i][k + 1])
					{
						++k;
						flag[i][j][i][k] = 1;
					}
				}
			}
		}
/*		for (int k = 1; k <= 8; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
				{
					if (flag[i][j][i + k][j])
						printf("(%d, %d) - (%d, %d)\n", i, j, i + k, j);
					if (flag[i][j][i][j + k])
						printf("(%d, %d) - (%d, %d)\n", i, j, i, j + k);
				}  */
		
		if (cnt)
		{
			cout << '\n';
			cout << "**********************************\n";
			cout << '\n';
		}
		cout << "Problem #" << ++cnt << "\n\n";
		bool flag1 = 1;
		for (int i = 1; i <= 8; ++i)
		{
			int num = 0;
			for (int j = 1; j <= n - i; ++j)
				for (int k = 1; k <= n - i; ++k)
				{
					if (flag[j][k][j][k + i] && flag[j][k][j + i][k] && flag[j][k + i][j + i][k + i] && flag[j + i][k][j + i][k + i])
						++num;
				}
			if (num)
			{
				flag1 = 0;
				printf("%d square (s) of size %d\n", num, i);
			}
		}
		if (flag1)
			cout << "No completed squares can be found.\n"; 
	} 
	return 0;
}

