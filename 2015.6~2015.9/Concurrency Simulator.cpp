#include<iostream>
#include<sstream>
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
typedef queue<string> tvv;
const int MAXN = 1e6 + 111;
int cost[5];
int va[26];
int n, q;

void init(tvv *v)
{
	for (int i = 0; i < 5; ++i) cin >> cost[i];
	cin >> q;
	getchar();
	string s;
	for (int i = 0; i < n; ++i)
	{
		while(getline(cin, s))
		{
			if (!s.length())
				continue;
			v[i].push(s);
			if (s == "end")
				break;
		}
	}
}

void solve(string& now, int& id)
{
	if (now[1] == 'r')
	{
		int index = now[6] - 'a';
		printf("%d: %d\n", id + 1, va[index]);
	}
	else
	{
		int index = now[0] - 'a';
		int sum = 0;
		if (now.length() == 5)
			sum = now[4] - '0';
		else sum = (now[4] - '0') * 10 + now[5] - '0';
		va[index] = sum;
	}
}

void ex(tvv *v)
{
	int now = 0;
	int lock = n;
	int len = n;
	int cnt = 0;
	while (1)
	{
		int lef = q;
		while(!v[now].empty() && lef > 0)
		{
			string s = v[now].front();
			if (s == "lock")
			{
				lef -= cost[2];
				if (lock == n)
				{
					lock = now;
					v[now].pop();
				}
				else break;
			}
			else if (s == "unlock")
			{
				lef -= cost[3];
				lock = n;
				v[now].pop();
			}
			else
			{
				if (s != "end")
				{
					if (s[1] == 'r')
						lef -= cost[1];
					else lef -= cost[0];
					solve(s, now);
					v[now].pop();
				}
				else 
				{
					v[now].pop();
					lef -= cost[4];
					++cnt;
				}
			}
		}
		now = (now + 1) % n;
		if (cnt == n) break;
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
		memset(va, 0, sizeof va);
		cin >> n;
		tvv v[15];
		init(v);
		ex(v);
		if (t) cout << '\n';
	}
	return 0;
}
