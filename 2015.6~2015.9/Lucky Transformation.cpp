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
const int MAXN = 1e5 + 111;

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n, k;
	string s;
	cin >> n >> k >> s;
	int stop = 0;
	if (k != 0){
	for (int i = 0; i < n - 1; ++i)
	{
		if (i + 2 < n && s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '7')
		{
			if ( (i + 2) % 2 == 0)
			{
				if ((k - stop) % 2)
					s[i + 1] = '7';
				break;
			}
		}
		else if (s[i] == '4' && s[i + 1] == '7')
		{
			if ((i + 1)% 2)
			{
				s[i + 1] = '4';
				++stop;
				i -= 1;
			}
			else 
			{
				s[i] = '7';
				++stop;
				i -= 2;
			}
			if (stop == k)
				break;
		}
	}
	}
	cout << s << '\n';
	return 0;
}

