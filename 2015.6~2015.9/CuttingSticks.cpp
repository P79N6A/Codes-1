#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 61;
int n,l;
bool cut[1111]; //��������������
int dp[1111][1111];

bool have(int l, int r) //��������Ƿ����и��
{
	for (int i = l; i <= r; ++i)
		if (cut[i]) return 1;
	return 0;
}

int dfs(int l, int r)
{
	int &ret = dp[l][r];
	if(!have(l,r)) return ret = 0; //û���и��
	if(l > r ) return ret = 0; //��Ч����
	if(ret < INF) return ret;
	for (int i = 1; i <= r; ++i)
	{
		if (cut[i])
		{
  			cut[i] = 0;
			ret = min(ret, dfs(l, i) + dfs(i + 1, r) + r - l + 1);
  			cut[i] = 1;
		}
	}
	return ret;
}

int main()
{
	while (cin >> l && l)
	{
		int x;
		cin >> n;
		memset(cut, 0, sizeof cut);
		memset(dp, 0x3f, sizeof dp);
		for (int i = 0; i < n; ++i) cin >> x, cut[x] = 1;
		int ans = INF;
		cout << "The minimum cutting is " << dfs(1, l) << ".\n";
	}
	return 0;
}

