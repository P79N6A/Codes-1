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

const int MAXN = 1e6 + 111;

struct C
{
	char color1, color2;
	bool operator == (const C& t)const
	{
		return ((color1 == t.color1 && color2 == t.color2) || (color1 == t.color2) && (color2 == t.color1));
	}
}cube[6];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string s;
	while (cin >> s)
	{
		string c1 = s.substr(0, 6);
		string c2 = s.substr(6, 6);
		cube[0].color1 = c1[0], cube[0].color2 = c1[5];
		cube[1].color1 = c1[2], cube[1].color2 = c1[3];
		cube[2].color1 = c1[1], cube[2].color2 = c1[4];
		cube[3].color1 = c2[0], cube[3].color2 = c2[5];
		cube[4].color1 = c2[2], cube[4].color2 = c2[3];
		cube[5].color1 = c2[1], cube[5].color2 = c2[4];
		bool flag = 0;
		if ((cube[0] == cube[3] && cube[1] == cube[4] && cube[2] == cube[5])
		 || (cube[0] == cube[3] && cube[1] == cube[5] && cube[2] == cube[4])
		 || (cube[0] == cube[4] && cube[1] == cube[3] && cube[2] == cube[5])
		 || (cube[0] == cube[4] && cube[1] == cube[5] && cube[2] == cube[3])
		 || (cube[0] == cube[5] && cube[1] == cube[3] && cube[2] == cube[4])
		 || (cube[0] == cube[5] && cube[1] == cube[4] && cube[2] == cube[3]))
		 {
		 	flag = 1;
		 }
		 cout << (flag ? "TRUE" : "FALSE") << '\n';
	}
	return 0;
}

