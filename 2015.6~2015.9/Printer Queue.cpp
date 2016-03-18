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
struct N{
	int id, num;
};

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int t; cin >> t;
	while (t --)
	{
		int m, n;
		cin >> n >> m;
		queue<N> q;
		priority_queue<int> pq;
		int mx = 0;
		for (int i = 0; i < n; ++i)
		{
			int num; cin >> num;
			N t;
			t.id = i; t.num = num;
			q.push(t);
			pq.push(num);
		}
		int cnt = 1;
		while (!q.empty())
		{
			N fq = q.front();
			int fpq = pq.top();
			//cout << fq.num << ' ' << fpq << endl;
			if (fq.num == fpq)
			{
				if (fq.id == m)
				{
					cout << cnt << '\n';
					break;
				}
				else
				{
					++cnt;
					pq.pop();
					q.pop();
				}
			}
			else
			{
				q.pop();
				q.push(fq);
			}
		}
	}
	return 0;
}
