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

map<string, int> mp;

int parse(string s)
{
	int res = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0; --i)
	{
		if (s[i] == '1')
			res += mul;
		mul *= 2;
	}
	return res;
}

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	
	mp["0"] = 1, mp["00"] = 2, mp["000"] = 5, mp["0000"] = 12,
	mp["00000"] = 27, mp["000000"] = 58, mp["0000000"] = 121;
	
	string h;
	while (getline(cin, h))
	{
		//cout << h << endl;
		string s, t;
		int codelen = 0, codemx = 0;
		int p = 0;
		bool flag = 1;
		while(flag && cin >> t)
		{
			s += t;
			for (int i = p; i < s.length() && flag; )
			{
				if (i + codelen > s.length())
					break;
				string now = s.substr(i, codelen);
				string codes(codelen, '0');
				i += codelen;
				
				int judge = parse(now);
				if (judge == codemx)
				{
					if (i + 3 > s.length())
						break;
					codelen = parse(s.substr(i,3));
					if (codelen == 0)
					{
						flag = 0;
						break;
					}
					i += 3;
					p = i;
					codemx = pow(2, codelen) - 1;
				}
				else
				{
					p = i;
					cout << h[mp[codes] + judge - 1]; 
				}
			}
		}
		
		getchar();
		if (s.length() != 3)
			cout << '\n';
	}
	return 0;
}

