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

const int MAXN = 1e4 + 111;

map<int, int> person;

int paiming[1011]; 

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int t;
	int cnt = 0;
	while (cin >> t && t)
	{
		int rnk = 1;
		int start = 1;
		queue<int> q[1011];
		memset(paiming, 0, sizeof paiming);
		int n;
		for (int i = 0; i < t; ++i)
		{
			cin >> n;
			int id;
			for (int j = 0; j < n; ++j)
			{
				cin >> id;
				person[id] = i;
			}
		}
		printf("Scenario #%d\n", ++cnt);
		string op;
		while(cin >> op && op[0] != 'S')
		{
			//cout << op[0] << endl;
			if (op[0] == 'E')
			{
				int num; cin >> num;
				int id = person[num];
				if (q[id].empty())
				{
					q[id].push(num);
					paiming[id] = rnk;
					++rnk;
				}
				else q[id].push(num);
			}
			else
			{
				for (int i = 0; i < t; ++i)
				{
					if (paiming[i] == start)
					{
						cout << q[i].front() << '\n';
						q[i].pop();
						if (q[i].empty())
						{
							++start;
						}
						break;
					}
				}
			}
		}
		cout << '\n';
	}
	return 0;
}

