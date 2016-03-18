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
int cnt, num[100]; //i次步骤到达的值 

bool dfs(int x, int dep)
{
	if(cnt > dep) return 0;
	if(num[cnt] == x) return 1;
	if(num[cnt] << (dep - cnt) < x) return 0;
	for( int i = 0; i <= cnt ; ++i )
	{
		++cnt;
		num[cnt] = num[cnt - 1] + num[i];
		if(num[cnt] <= 1000 && dfs(x, dep)) return 1;
		num[cnt] = num[cnt - 1] - num[i];
		if(num[cnt] > 0 && dfs(x, dep)) return 1;
		--cnt;
	}
	return 0;
}

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n && n)
	{
		int temp = n;
		int dep = -1;
		while( temp )
		{
			++dep;
			temp >>= 1;
		}
		//cout << dep << endl;
		for (int ans = dep; ; ++ans)
		{
			cnt = 0; //步数 
			num[0] = 1;
			if ( dfs(n, ans) )
			{
				cout << ans << '\n';
				break;
			}
		}
	}
	return 0;
}
