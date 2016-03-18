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

const int MAXN = 1e6 + 111;

int main()
{
	string s;
	int n; cin >> n;
	while (n --)
	{
		cin >> s;
		int ans = 0, cnt = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'O')
			{
				++cnt;
				ans += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

