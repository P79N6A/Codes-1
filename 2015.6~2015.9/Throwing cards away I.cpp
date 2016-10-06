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

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n;
	while (cin >> n && n)
	{
		deque<int> dq;
		for (int i = 1; i <= n; ++i)
			dq.push_back(i);
		cout << "Discarded cards:";
		for (int i = 1; i < n; ++i)
		{
			cout << ' ' << dq.front();
			if (i != n - 1)
				cout << ',';
			dq.pop_front();
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << "\nRemaining card: " << dq.front() << '\n';
	}
	return 0;
}

