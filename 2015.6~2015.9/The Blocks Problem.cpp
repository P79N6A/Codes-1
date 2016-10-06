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

const int MAXN = 30;

vector<int> pile[MAXN]; 

int n;

void find_block(int f, int& p, int& h)
{
	for (p = 0; p < n; ++p)
	{
		for (h = 0; h < pile[p].size(); ++h)
		{
			if (pile[p][h] == f)
				return;
		}
	}
}

void clear_above(int p, int h)
{
	for (int i = h + 1; i < pile[p].size(); ++i)
	{
		int now = pile[p][i];
		pile[now].push_back(now);
	}
	pile[p].resize(h + 1);
}

void pile_onto(int p1, int p2, int h)
{
	for (int i = h; i < pile[p1].size(); ++i)
	{
		pile[p2].push_back(pile[p1][i]);
	}
	pile[p1].resize(h);
}

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	cin >> n;
	string s1, s2;
	int a, b;
	for (int i = 0; i < n; ++i)
		pile[i].push_back(i);
	while (cin >> s1 >> a >> s2 >> b)
	{
		if (s1 == "quit")
			break;
		int pa = 0, pb = 0, ha = 0, hb = 0;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa == pb)
			continue;
		if (s2 == "onto")
			clear_above(pb, hb);
		if (s1 == "move")
			clear_above(pa, ha);
		pile_onto(pa, pb, ha);
	}
	for (int i = 0; i < n; ++i, putchar('\n'))
	{
		cout << i << ':';
		for (int j = 0; j < pile[i].size(); ++j)
		{
			cout << ' ' << pile[i][j];
		}
	}
	return 0;
}

