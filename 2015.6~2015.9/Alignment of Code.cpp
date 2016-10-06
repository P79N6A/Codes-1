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

vector<string> v[MAXN];
vector<int> l;

void print(int len)
{
	for (int i = 0; i < len; ++i)
		printf(" ");
}

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string s;
	int row = 0;
	int mx = 0;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); ++i)
		{
			string t;
			int len = 0;
			while (s[i] != ' ')
			{
				while(i + len < s.length() && s[i + len] != ' ')
				{
					t += s[i + len];
					++len;
				}
				v[row].push_back(t);
				i = i + len;
				break;
			}
		}
		if (v[row].size() > mx)
			mx = v[row].size(); 
		++row;
	}
	for (int i = 0; i < mx; ++i)
	{
		int mxl = 0;
		for (int j = 0; j < row; ++j)
		{
			if (v[j].size() > i && v[j][i].length() > mxl)
				mxl = v[j][i].length();
		}
		l.push_back(mxl);
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j];
			if (j != v[i].size() - 1)
				print(l[j] + 1 - v[i][j].length());
		}
		cout << '\n'; 
	}
	return 0;
}

