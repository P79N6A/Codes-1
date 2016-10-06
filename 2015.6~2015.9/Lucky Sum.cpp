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
const int MAXN = 1e4;
typedef long long ll;
ll num[MAXN];
int cnt = 0;

void dfs(ll sum)
{
	if (sum > 1e9)
	{
		num[cnt++] = sum;
		return;
	}
	num[cnt++] = sum;
	dfs(sum * 10 + 4);
	dfs(sum * 10 + 7);
} 

int main()
{
	ll l, r;
	dfs(0);
	sort(num, num + cnt);
	cin >> l >> r;
	int s = 100000, e = 0;
	for (int i = 0; i < cnt; ++i)
	{
		if (num[i] >= l) s = min(s, i);
		if (num[i] >= r) { e = i; break;}	
	}
	ll ans = 0;
	//cout << cnt << endl;
	while (s < e)
	{
		ans += (num[s] - l + 1) * num[s];
		l = num[s] + 1;
		++s;
	}
	ans += num[e] * (r - l + 1);
	cout << ans << '\n';
	return 0;
}

