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
int stone[MAXN];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n, q;
	int cnt = 0;
	while (cin >> n >> q && (n || q))
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> stone[i];
		}
		sort(stone + 1, stone + n + 1);
		cout << "CASE# " << ++cnt << ":\n";
		int x;
		for (int i = 0; i < q; ++i)
		{
			cin >> x;
			int p = lower_bound(stone + 1, stone + 1 + n, x) - &stone[1]; 
		//	cout << p << endl;
			if (p + 1 <= n && stone[p + 1] == x)
				printf("%d found at %d\n", x, p + 1);
			else printf("%d not found\n", x);
		}
	}
	return 0;
}

