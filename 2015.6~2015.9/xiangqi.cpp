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

bool flag[20][20];
bool has[20][20];

struct Node
{
	char name;
	int x, y;
}node[10];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n, x, y;
	while (cin >> n >> x >> y && (n || x || y))
	{
		memset(flag, 0, sizeof flag);
		memset(has, 0, sizeof has);
		for (int i = 0; i < n; ++i)
		{
			cin >> node[i].name >> node[i].x >> node[i].y;
			has[node[i].x][node[i].y] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			switch(node[i].name)
			{
				case 'G':
					{
						for (int j = node[i].x - 1; j >= 1; --j)
						{
							if (!has[j][node[i].y])
							{
								flag[j][node[i].y] = 1;
							}
							else
							{
								flag[j][node[i].y] = 1;
							 	break;
							}
						}
						break;
					}
				case 'R':
					{
						for (int j = node[i].x - 1; j >= 1; --j)
						{
							if (!has[j][node[i].y])
							{
								flag[j][node[i].y] = 1;
							}
							else
							{
								flag[j][node[i].y] = 1;
								break;
							}
						}
						for (int j = node[i].x + 1; j <= 10; ++j)
						{
							flag[j][node[i].y] = 1;
							if (!has[j][node[i].y])
							{
								
							}
							else break;
						}
						for (int j = node[i].y - 1; j >= 1; --j)
						{
							flag[node[i].x][j] = 1;
							if (!has[node[i].x][j])
							{
								
							}
							else break;
						}
						for (int j = node[i].y + 1; j <= 9; ++j)
						{
							flag[node[i].x][j] = 1;
							if (!has[node[i].x][j])
							{
								
							}
							else break;
						}
						break;
					}
				case 'H':
					{
						int tx = node[i].x, ty = node[i].y;
						if (!has[tx - 1][ty])
						{
							if (tx - 2 >= 1)
								flag[tx - 2][ty - 1] = flag[tx - 2][ty + 1] = 1;
						}
						if (!has[tx + 1][ty])
						{
							if (tx + 2 <= 10)
								flag[tx + 2][ty - 1] = flag[tx + 2][ty + 1] = 1;
						}
						if (!has[tx][ty - 1])
						{
							if (ty - 2 >= 1)
								flag[tx - 1][ty - 2] = flag[tx + 1][ty - 2] = 1;
						}
						if (!has[tx][ty + 1])
						{
							if (ty + 2 <= 9)
								flag[tx - 1][ty + 2] = flag[tx + 1][ty + 2] = 1;
						}
						break;
					}
				case 'C':
					{
						bool flag1 = 0;
						for (int j = node[i].x - 1; j >= 1; --j)
						{
							if (has[j][node[i].y])
							{
								if (flag1) break;
								flag1 = 1;
							}
							else if (flag1)
							{
								flag[j][node[i].y] = 1;
							}
						}
						flag1 = 0;
						for (int j = node[i].x + 1; j <= 10; ++j)
						{
							if (has[j][node[i].y])
							{
								if (flag1) break;
								flag1 = 1;
							}
							else if (flag1)
							{
								flag[j][node[i].y] = 1;
							}
						}
						flag1 = 0;
						for (int j = node[i].y - 1; j >= 1; --j)
						{
							if (has[node[i].x][j])
							{
								if (flag1) break;
								flag1 = 1;
							}
							else if (flag1)
							{
								flag[node[i].x][j] = 1;
							}
						}
						flag1 = 0;
						for (int j = node[i].y + 1; j <= 9; ++j)
						{
							if (has[node[i].x][j])
							{
								if (flag1) break;
								flag1 = 1;
							}
							else if (flag1)
							{
								flag[node[i].x][j] = 1;
							}
						}
						break;
					}
			}
		}
		if (x == 1)
			flag[0][y] = 1;
		if (y == 4)
			flag[x][3] = 1;
		if (y == 6)
			flag[x][7] = 1;
		if (x == 3)
			flag[4][y] = 1;
	/*	cout << flag[x + 1][y] << endl;
		cout << flag[x - 1][y] << endl;
		cout << flag[x][y + 1] << endl;
		cout << flag[x][y - 1] << endl; */
		if (flag[x + 1][y] && flag[x - 1][y] && flag[x][y + 1] && flag[x][y - 1])
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

