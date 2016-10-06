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

const int MAXN = 1E5 + 111;

bool flag[MAXN];
int x[MAXN], h[MAXN];
int w[MAXN];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> h[i];
	x[0] = -0x7f7f7f7f;
	x[n + 1] = 0x7f7f7f7f;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (x[i] - h[i] > x[i - 1])
		{
			++ans;
			continue;
		}
		if (x[i] + h[i] < x[i + 1])
		{
			++ans;
			x[i] += h[i];
		}
	}
	cout << ans << '\n';
	return 0;
}

