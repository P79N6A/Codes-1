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

const int MAXN = 1e3 + 111;

struct Node{
	int x, y;
	bool operator < (const Node& t)const
	{
		return x < t.x;
	}
}node[MAXN];

bool cmp1(Node a, Node b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else return a.x < b.x;
}

bool cmp2(Node a, Node b)
{
	if (a.x == b.x)
		return a.y > b.y;
	else return a.x < b.x;
}

int main()
{
	int t; cin >> t;
	int n;
	while (t --)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> node[i].x >> node[i].y;
		}
		sort(node, node + n);
		sort(node, node + n / 2, cmp1); //����y��С�������� 
		sort(node + n / 2, node + n, cmp2); //�Ұ�ߴӴ�С���� 
		int mid = node[0].x + node[n - 1].x;  //�Գ��������һ���ǵ�һ���ڵ�����һ���ڵ�ĺ� 
		bool flag = 1;
		for (int i = 0; i < n / 2; ++i) // �����ж϶Գ�����ͬ�������ͬȻ���ж��Ƿ���ͬһˮƽ���� 
		{ 
			if (node[i].x + node[n - i - 1].x != mid || (node[i].x != node[n - i - 1].x && node[i].y != node[n - i - 1].y))
			{
				//cout << mid << endl;
				//cout << i << ':' << node[i].x << ' ' << node[i].y << endl;
				//cout << n - i - 1 << ':' << node[n - i - 1].x << ' ' << node[n - i - 1].y << endl;
				flag = 0;
				break;
			}
		}
		cout << (flag ? "YES\n":"NO\n");
	}
	return 0;
}

