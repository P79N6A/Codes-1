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
double x[200], y[200];

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	double k;
	cin >> n >> k;
	double ans = 0;
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n - 1; ++i)
	{
		ans += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1])* (y[i] - y[i + 1]));
	}
	printf("%.9lf\n", ans * k / 50.0);
	return 0;
}

