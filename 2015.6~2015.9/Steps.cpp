#include<iostream>
#include<cctype>
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
typedef long long ll;

int main()
{
	ll ans = 0;
	int n, m, nx, ny, k, x, y;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < k; ++i)
	{
		int nnx, nny, tem;
		cin >> nx >> ny;
		if (nx > 0) nnx = (n - x) / nx;
		else if (nx < 0) nnx = (x - 1) / -nx;
		if (ny > 0) nny = (m - y) / ny;
		else if (ny < 0) nny = (y - 1) / -ny;
		if (nx == 0) tem = nny;
		else if (ny == 0) tem = nnx;
		else tem = min(nnx, nny);
		x = x + nx * tem;
		y = y + ny * tem;
		ans += tem;
		//cout <<'(' << x << ',' << y << ')' << endl;
	}
	cout << ans << '\n';
	return 0;
}

