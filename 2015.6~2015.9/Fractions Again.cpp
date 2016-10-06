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

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			if (i * n % (i - n) == 0 && i * n / (i - n) >= i)
				++cnt;
		}
		cout << cnt << '\n';
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			if (i * n % (i - n) == 0 && i * n / (i - n) >= i)
				printf("1/%d = 1/%d + 1/%d\n", n, i * n / (i - n), i);
		}
	}
	return 0;
}

