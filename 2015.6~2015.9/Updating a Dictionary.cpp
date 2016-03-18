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

const int MAXN = 1e3 + 111;

struct N{
	string k, v;
	bool operator < (const N& t)const
	{
		return k < t.k;
	}
}node[2][MAXN]; 

int cnt[2];

map<string, string> ktov; //K->V
map<string, string> ktov2;

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int cs;
	cin >> cs;
	while (cs --)
	{
		string s1, s2;
		ktov.clear();
		ktov2.clear();
		cin >> s1 >> s2;
		cnt[0] = 0;
		for (int i = 1; i < s1.length(); ++i)
		{
			if (s1[i] == '}')
				break;
			string t;
			for (int j = 0; ; ++j)
			{
				if (s1[i + j] != ':')
					t += s1[i + j];
				else
				{
					++j;
					i += j;
					break;
				}
			}
			node[0][cnt[0]].k = t;
			t.clear();
			for (int j = 0; ; ++j)
			{
				if (s1[i + j] != ',' && s1[i + j] != '}')
					t += s1[i + j];
				else
				{
					i += j;
					break;
				} 
			}
			node[0][cnt[0]].v = t;
			N tem = node[0][cnt[0]];
			ktov[tem.k] = tem.v;
			++cnt[0];
		}
		
		cnt[1] = 0;
		for (int i = 1; i < s2.length(); ++i)
		{
			if (s2[i] == '}')
				break;
			string t;
			for (int j = 0; ; ++j)
			{
				if (s2[i + j] != ':')
					t += s2[i + j];
				else
				{
					++j;
					i += j;
					break;
				}
			}
			node[1][cnt[1]].k = t;
			t.clear();
			for (int j = 0; ; ++j)
			{
				if (s2[i + j] != ',' && s2[i + j] != '}')
					t += s2[i + j];
				else
				{
					i += j;
					break;
				} 
			}
			node[1][cnt[1]].v = t;
			N tem = node[1][cnt[1]];
			ktov2[tem.k] = tem.v;
			++cnt[1];
		}
		
		sort(node[1], node[1] + cnt[1]);
		sort(node[0], node[0] + cnt[0]);
		bool flag1 = 0, flag2 = 0, flag3 = 0;
		string ans1 = "+", ans2 = "-", ans3 = "*";
		string ans4 = "No changes";
		
		for (int i = 0; i < cnt[1]; ++i)
		{
			if(ktov[node[1][i].k] == "")
			{
				flag1 = 1;
				ans1 += node[1][i].k + ',';
			}
		}
		for (int i = 0; i < cnt[0]; ++i)
		{
			if (ktov2[node[0][i].k] == "")
			{
				flag2 = 1;
				ans2 += node[0][i].k + ',';
			}
		}
		for (int i = 0; i < cnt[0]; ++i)
		{
			string nowk = node[0][i].k;
			string nowv = node[0][i].v;
			if (ktov2[nowk] != "" && nowv != ktov2[nowk])
			{
				flag3 = 1;
				ans3 += nowk + ',';
			}
		}
		
		
		if (flag1)
		{
			for (int i = 0; i < ans1.length() - 1; ++i)
				cout << ans1[i];
			cout << '\n';
		}
		if (flag2)
		{
			for (int i = 0; i < ans2.length() - 1; ++i)
				cout << ans2[i];
			cout << '\n';
		}
		if (flag3)
		{
			for (int i = 0; i < ans3.length() - 1; ++i)
				cout << ans3[i];
			cout << '\n';
		}
		if (!flag1 && !flag2 && !flag3)
		{
			cout << ans4 << '\n';
		}
		//cout << ktov["c"] << ' ' << ktov2["c"] << endl;
		cout << '\n';
	}
	return 0;
}

