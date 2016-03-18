#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
struct M{
	long long  a, b;
}m[26];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n; cin >> n;
	char c;
	long long a, b, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> a >> b;
		m[c - 'A'].a = a, m[c - 'A'].b = b;
	}
	vector<M> alp;
	string s;
	while (cin >> s)
	{
		ans = 0;
		bool flag = 1;
		alp.clear();
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if (isalpha(s[i]))
			{
				alp.push_back(m[s[i] - 'A']);
			}
			else if (s[i] == ')')
			{
				if (alp.size() < 2)
					continue;
				M t1 = alp.back(); alp.pop_back();
				M t2 = alp.back(); alp.pop_back();
				if (t2.b == t1.a)
				{
					ans += t2.a * t2.b * t1.b;
					M t;
					t.a = t2.a; t.b = t1.b;
					alp.push_back(t);
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
		{
			//cout << alp.size() << endl;
			cout << ans << '\n';
		}
		else cout << "error\n";
	}
	return 0;
}

