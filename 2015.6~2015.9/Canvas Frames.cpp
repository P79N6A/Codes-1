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
int num[111];

int main()
{
#ifdef LOCAL
//	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		int x;
		memset(num, 0, sizeof num);
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			++num[x];
		}
		int sum = 0;
		for (int i = 1; i <= 100; ++i)
		{
			sum += num[i] / 2;
		}
		cout << sum / 2 << '\n';
	}
	return 0;
}

