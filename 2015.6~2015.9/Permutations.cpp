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
const int MAXN = 1e6 + 111;
string s[10];
int num[10];
int n, k;

int parse(string s)
{
	int ret = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}

string conver(string s)
{
	string ret;
	for (int i = 0; i < k; ++i)
	{
		ret += s[num[i]];
	}
	return ret;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < k; ++i) num[i] = i;
	int ans = 1000000000;
	do
	{
		int mi = 1000000000, mx = 0;
		for (int j = 0; j < n; ++j)
		{
			string tem = conver(s[j]);
			//cout << tem << endl;
			int now = parse(tem);
			//cout << now << endl;
			mx = max(now, mx);
			mi = min(now, mi);
		}
		ans = min(ans, mx - mi);
	}while(next_permutation(num, num + k));
	cout << ans << '\n';
	return 0;
}

