#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<cctype>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
bool mp[30][30];
bool have[30];
vector<int> V;
vector<int> P;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	string s;
	while (cin >> s && s != "#")
	{
		V.clear();
		P.clear();
		memset(mp, 0, sizeof mp);
		memset(have, 0, sizeof have);
		bool enter = 1;
		int u, v;
		for (int i = 0; i < s.length(); ++i)
		{
			if (isalpha(s[i]))
			{
				if (enter) { u = s[i] - 'A'; if (!have[u]) V.push_back(u), have[u] = 1;}
				else
				{
					v = s[i] - 'A';
					if (!have[v]) { V.push_back(v); have[v] = 1;}
					mp[u][v] = mp[v][u] = 1;
				}
			}
			else if (s[i] == ':') enter = 0;
			else enter = 1;
		}
		sort(V.begin(), V.end());
		int ans = 20;
		do
		{
			int dis = 1;
			bool can = true;
			for (int i = 0; i < V.size(); ++i)
			{
				for (int j = i + 1; j < V.size(); ++j)
				{
					if (mp[V[i]][V[j]])
					{
						dis = max(dis, j - i);
						if (dis >= ans)
						{
							can = false; break;
						}
					}
				}
				if (!can) break;
			}
			if (can) { P = V, ans = dis;}
		}while (next_permutation(V.begin(), V.end()));
		for (int i = 0; i < P.size(); ++i)
		{
			if (i) cout << ' ';
			cout << char(P[i] + 'A');
		}
		cout << " -> " << ans << '\n';
	}
	return 0;
}

