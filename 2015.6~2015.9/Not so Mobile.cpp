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
int w1, d1, w2, d2;

bool same(int w1, int d1, int w2, int d2)
{
	int a, b, c, d;
	if (w1 == 0 && w2 != 0)
	{
		cin >> a >> b >> c >> d;
		return same(a, b, c, d);
	}
	else if (w2 == 0 && w1 != 0)
	{
		cin >> a >> b >> c >> d;
		return same(a, b, c, d);
	}
	else if (w1 == 0 && w2 == 0)
	{
		cin >> a >> b >> c >> d;
		bool flag1 = same(a, b, c, d);
		cin >> a >> b >> c >> d;
		bool flag2 = same(a, b, c, d);
		return (flag1 && flag2);
	}
	else return (w1 * d1 == w2 * d2);
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t --)
	{
		cin >> w1 >> d1 >> w2 >> d2;
		if (same(w1, d1, w2, d2)) cout << "YES\n";
		else cout << "NO\n"; 
		if (t != 0)
			cout << '\n';
	}
	return 0;
}

