#include<iostream>
#include<cctype>
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
string a[2];
int ans[100];

int num(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else return c - 'A' + 10;
}

bool can(int mx, int mxv, int numb)
{
	int sum = 0, po = 1;
	for (int i = a[numb].length() - 1; i >= 0; --i)
	{
		sum += num(a[numb][i]) * po;
		po *= mx;
	}
	if (sum < mxv) return 1;
	else return 0;
}

int main()
{
	int p = 0;
	string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
		if (s[i] == ':') p = i;
    a[0] = s.substr(0,p), a[1] = s.substr(p + 1);
    int mx = 0;
    for (int j = 0; j < 2; ++j)
    	for (int i = 0; i < a[j].length(); ++i)
			mx = max(mx, num(a[j][i]));
    ++mx;
    int len = 0;
    while (1)
    {
    	if (can(mx, 24, 0) && can(mx, 60, 1))
    	{
			ans[len++] = mx;
    		if (mx == 60) break;
    	}
    	else break;
    	++mx;
    }
    if (ans[0] == 0) cout << 0 << '\n';
    else if (ans[len - 1] == 60) cout << -1 << '\n';
    else
    {
    	cout << ans[0];
    	for (int i = 1; i < len; ++i)
			cout << ' ' << ans[i];
		cout << '\n';
	}
	return 0;
}

