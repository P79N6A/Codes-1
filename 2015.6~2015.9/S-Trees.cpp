#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
struct OP{
	int id;
	string x;
	bool operator < (const OP& t)const
	{
		return x < t.x;
	}
}op[7];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	int to[7];
	string bottom;
	int kase = 0;
	while (cin >> n && n)
	{
		cout << "S-Tree #" << ++kase << ":\n"; 
		memset(to, 0, sizeof to);
		for (int i = 0; i < n; ++i) { cin >> op[i].x; op[i].id = i;}
		sort(op, op + n);
		for (int i = 0; i < n; ++i) {to[i] = op[i].id;}
		cin >> bottom;
		int t;
		cin >> t;
		string doo;
		for (int i = 0; i < t; ++i)
		{
			cin >> doo;
			int num = 0;
			for (int i = 0; i < n; ++i)
			{
				if (doo[i] == '1')
				{
					int p = n - to[i] - 1;
					num += pow(2, p);
				}
			}
			//cout << num << endl;
			cout << bottom[num];
		}
		cout << "\n\n";
	}
	return 0;
}

