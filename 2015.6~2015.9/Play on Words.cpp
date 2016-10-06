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
int inAlp[30], outAlp[30];
bool can[30][30];
bool vis[30];
bool judge, flag;
int sum;

void ok(int& node)
{
	vis[node] = 1;
	for (int i = 0; i < 26; ++i)
	{
		if (can[node][i] && !vis[i])
		{
			ok(i);
			++sum;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n, t; cin >> t;
	while (t --)
	{
		memset(vis, 0, sizeof vis);
		memset(can, 0, sizeof can);
		cin >> n;
		string s;
		memset(inAlp, 0, sizeof inAlp);
		memset(outAlp, 0, sizeof outAlp);
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			int len = s.length();
			++inAlp[s[0] - 'a'];
			++outAlp[s[len - 1] - 'a'];
			can[s[0] - 'a'][s[len - 1] - 'a'] = 1;
		}
		flag = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (inAlp[i])
			{
				sum = 1;
				ok(i);
				break;
			}
		}
		//cout << sum << endl;
		for (int i = 0; i < 26; ++i)
		{
			if (inAlp[i] || outAlp[i])
				--sum;
		}
		//cout << sum << endl;
		if (sum == 0)
			flag = 1;
		judge = 1;
		int neg = 0, posi = 0;
		for (int i = 0; i < 26; ++i)
		{
			int t = inAlp[i] - outAlp[i];
			if (t < 0)
			{
				if(t == -1)
				{
					++neg;
					if (neg > 1)
					{
						judge = 0;
						break;
					}
				}
				else
				{
					judge = 0;
					break;
				}
			}
			else if (t > 0)
			{
				if (t == 1)
				{
					++posi;
					if (posi > 1)
					{
						judge = 0;
						break;
					}
				}
				else
				{
					judge = 0;
					break;
				}
			}
		}
		if (judge && flag)
			cout << "Ordering is possible.\n";
		else cout << "The door cannot be opened.\n";
	}
	return 0;
}

