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
typedef long long ll;
map<ll, int> cnt;
string s;
int sum;

void dfs(int depth, int b, int e)
{
	if (s[b] == '[')
	{
		int p = 0;
		for (int i = b + 1; i <= e; ++i)
		{
			if (s[i] == '[') ++p;
			if (s[i] == ']') --p;
			if (!p && s[i] == ',')
			{
				dfs(depth + 1, b + 1, i - 1);
				dfs(depth + 1, i + 1, e - 1);
			}
		}
	}
	else
	{
		ll w = 0;
		for (int i = b; i <= e; ++i)
			w = w * 10 + s[i] - '0';
		++sum, ++cnt[w << depth];
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t --)
	{
		cin >> s;
		cnt.clear();
		sum = 0;
		dfs(0, 0, s.size() - 1);
		int mx = 0;
		map<ll, int>::iterator it;
		for (it = cnt.begin(); it != cnt.end(); ++it)
		{
			mx = max(mx, it->second);
		}
		cout << sum - mx << '\n';
	}
	return 0;
}

