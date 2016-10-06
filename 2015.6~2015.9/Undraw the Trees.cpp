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
const int MAXN = 2e2 + 111;
int cnt;

void dfs(char a, int x, int y, string *s)
{
	cout << a << '(';
	int down = 1, l = 0, r = 0;
	if (s[x + 1][y] != '|'){cout << ')'; return;}
	while (s[x + down][y] != '-') ++down;
	while (y - l > 0 && s[x + down][y - l] != ' ' ) ++l;
	while (y + r < s[x + down].length() && s[x + down][y + r] != ' ') ++r;
	for (int i = y - l; i < min(y + r, (int)s[x + down + 1].length()); ++i)
	{
		if (s[x + down + 1][i] != '|' && s[x + down + 1][i] != ' ' && s[x + down + 1][i] != '\0')
		{
			//cout << "\nenter:" << s[x + down + 1][i] << endl;
			dfs(s[x + down + 1][i], x + down + 1, i, s);
		}
	}
	cout << ')';
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t; cin >> t; cin.get();
	while (t --)
	{
		cnt = 0;
		string s[MAXN];
		while (getline(cin, s[cnt]))
		{
			//cout << s[cnt] << '\n';
			if (s[cnt++][0] == '#') break;
		}
		cout << '(';
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = 0; j < s[i].length(); ++j)
			{
				if (s[i][j] != '|' && s[i][j] != '-' && s[i][j] != '#' && s[i][j] != ' ')
				{
					dfs(s[i][j], i, j, s);
					goto xx;
				}
			}
		}
		xx:
		cout << ")\n";
	}
	return 0;
}

