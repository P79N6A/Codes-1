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
int s[100];
int cnt;
int n, l;

bool dfs(int cur)
{
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; ++i)
		{
			if (i != 0 && i % 64 == 0) cout << '\n';
			else if (i % 4 == 0 && i != 0) cout << ' ';
			cout << char(s[i] + 'A'); 
		}
		cout << '\n' << cur << '\n';
		return 0;
	}
	for (int i = 0; i < l; ++i)
	{
		s[cur] = i;
		bool ok = 1;
		for (int j = 1; j * 2 <= cur + 1; ++j)
		{
			bool equal = 1;
			for (int k = 0; k < j; ++k)
				if (s[cur - k] != s[cur - k - j]){ equal = 0; break;}
			if (equal) {ok = 0; break;}
		}
		if (ok && !dfs(cur + 1)) return 0;
	}
	return 1;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	
	while (cin >> n >> l && (n || l))
	{
		cnt = 0;
		dfs(0);
	}
	return 0;
}

