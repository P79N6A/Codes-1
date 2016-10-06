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

const int MAXN = 1001;
const double eps = 1e-7;
double h[MAXN];

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int m, n; 
	int c = 0;
	while(cin >> m >> n && (m || n))
	{
		int len = m * n;
		for (int i = 0; i < len; ++i)
		{
			cin >> h[i];
		}
		sort(h, h + len);
		double left;
		cin >> left;
		left /= 100.0;
		int cnt = 1;
		double aver = h[0];
		for (int i = 0; i < len - 1; ++i)
		{
			double add = cnt * (h[i + 1] - h[i]);
			left -= add;
			if (left - eps < 0.0)
			{
				left += add;
				break;
			}
			aver = h[i + 1];
			++cnt;
		}
	//	cout << cnt << endl;
		printf("Region %d\n", ++c);
		printf("Water level is %.2lf meters.\n", aver + left / (double)cnt);
		printf("%.2lf percent of the region is under water.\n\n", (double)cnt / (double)len * 100.0); 
	}
	return 0;
}

