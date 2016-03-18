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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

char mp[6][6];

struct Node{
	int p;
	int id;
	int x, y;
}node[26];

queue<Node> q; 

void ans(int l)
{
	if (node[l].p != 0)
	{
		ans(node[l].p);
	}
	cout << '(' << node[l].x << ',' << ' ' << node[l].y << ')' << '\n';
}

int main()
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> mp[i][j];
	node[0].x = 0, node[0].y = 0;
	node[0].id = 0;
	q.push(node[0]);
	mp[0][0] = '1';
	bool flag1 = 0;
	int len = 0;
	while (!q.empty())
	{
		Node t = q.front(); q.pop();
		int p = t.id;
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dir[i][0], ny = t.y + dir[i][1];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && mp[nx][ny] == '0' ) 
			{
				mp[nx][ny] = '1';
				++len;
				node[len].p = p;
				node[len].id = len;
				node[len].x = nx, node[len].y = ny;
				if (nx == 4 && ny == 4)
				{
					flag1 = 1;
					break;
				}
				q.push(node[len]);
			}
		}
		if (flag1)
			break;
	}
	cout << "(0, 0)\n";
	ans(len);
	return 0;
}

