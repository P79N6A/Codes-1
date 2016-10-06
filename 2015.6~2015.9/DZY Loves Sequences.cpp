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

const int MAXN = 1e5 + 1111;
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int len = 0;
	for (int i = 0; i < n - 1; i += len)
	{
		len = 1;
		dp2[i] = 1;
		for (int j = i + 1; a[j] > a[j - 1] && j < n; ++j)
		{
			dp2[j] = dp2[j - 1] + 1;
			len = dp2[j];
		} 
	}
	for (int i = n - 1; i >= 0; i -= len)
	{
		len = 1;
		dp1[i] = 1;
		for (int j = i - 1; a[j + 1] > a[j] && j >= 0; --j)
		{
			dp1[j] = dp1[j + 1] + 1;
			len = dp1[j];
		}
	}
	int mx = dp1[0] - 1;
	for (int i = 0; i < n; ++i)
	{
		if (i < n - 2 && a[i] + 1 < a[i + 2])
			mx = max(mx, dp2[i] + dp1[i + 2]);
		if (i < n - 1 && a[i] >= a[i + 1])
			mx = max(mx, dp1[i + 1]);
		if (i > 0 && a[i] <= a[i - 1])
			mx = max(mx, dp2[i - 1]);
		//cout << mx << endl;
	}
	cout << mx + 1 << '\n';
	return 0;
}

