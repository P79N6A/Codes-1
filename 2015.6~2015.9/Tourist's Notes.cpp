#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int MAXN = 1e5 + 111;

int d[MAXN], h[MAXN];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> d[i] >> h[i];
	bool flag = 0;
	int ans = h[1] + d[1] - 1;
	for (int i = 2; i <= m; ++i)
	{
		if (abs(h[i] - h[i - 1]) > d[i] - d[i - 1])
		{
			flag = 1;
			break;
		}
		else
		{
			int mxh = max(h[i], h[i - 1]);
			int left = d[i] - d[i - 1] - abs(h[i] - h[i - 1]);
			ans = max(ans, mxh + left / 2);
		}
	}
	ans = max(ans, h[m] + (n - d[m]));
	if (flag)
		cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
	return 0;
}

