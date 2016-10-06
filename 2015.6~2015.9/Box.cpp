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

struct R
{
	int a, b;
	bool operator < (const R& t)const
	{
		if (a != t.a)
			return a < t.a;	
		else return b < t.b;
	}
}r[7];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	while (cin >> r[0].a >> r[0].b)
	{
		for (int i = 1; i <= 5; ++i)
			cin >> r[i].a >> r[i].b;
		for (int i = 0; i < 6; ++i)
		{
			R &t = r[i];
			if (t.a > t.b)
				swap(t.a, t.b);
		}
		sort(r, r + 6);
		bool flag = 1;
		//for (int i = 0; i < 6; ++i) cout << r[i].a << ' ' << r[i].b << endl;
		for (int i = 0; i < 6; i += 2)
		{
			if (r[i].a != r[i + 1].a || r[i].b != r[i + 1].b)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			if (r[0].a != r[2].a)
				flag = 0;
			else
			{
				if ((r[0].b == r[4].a && r[2].b == r[4].b) || (r[0].b == r[4].b && r[2].b == r[4].a))
					;
				else flag = 0; 
			}
		}
		cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	}
	return 0;
}

