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
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t;
	while(cin >> t && t != -1)
	{
		int d, n;
		while (t --)
		{
			cin >> d >> n;
			n -= 1;
			int k = 1;
			for (int i = 1; i < d; ++i)
			{
				if (n & 1) { k = k * 2 + 1;}
				else { k = k * 2;} 
				n = n >> 1;
			}
			cout << k << '\n';
		}
	}
	return 0;
}

