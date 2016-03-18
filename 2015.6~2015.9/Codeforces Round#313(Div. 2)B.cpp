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
int a[3], b[3];

bool small(int x1, int y1, int x2, int y2)
{
	return ((x1 >= x2 && y1 >= y2) || (x1 >= y2 && y1 >= x2));
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i] >> b[i];
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	int ll, lw;
	ll = b[0] - b[1], lw = a[0] - a[1];
	if (ll >= 0 && lw >= 0 &&(small(ll, a[0], a[2], b[2]) || small(lw, b[0], a[2], b[2])))
		cout << "YES\n";
	else 
	{
		ll = b[0] - a[1], lw = a[0] - b[1];
		if (ll >= 0 && lw >= 0 &&(small(ll, a[0], a[2], b[2]) || small(lw, b[0], a[2], b[2])))
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

