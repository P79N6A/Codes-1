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

const int MAXN = 1e3 + 111;
char s[55][MAXN];
int num[100];

int main()
{
	int t; cin >> t;
	while (t --)
	{
		string ss;
		int ans = 0;
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> s[i][j];
		for (int i = 0; i < n; ++i)
		{
			memset(num, 0, sizeof num); 
			for (int j = 0; j < m; ++j)
			{
				++num[s[j][i]];
			}
			int mx = 0, p = 0;
			for (int j = 'A'; j <= 'T'; ++j)
			{
				if (num[j] > mx)
				{
					mx = num[j];
					p = j;
				}
			}
			ss += (char)p;
			ans += m - mx; 
		}
		cout << ss << '\n';
		cout << ans << '\n';
	}
	return 0;
}

