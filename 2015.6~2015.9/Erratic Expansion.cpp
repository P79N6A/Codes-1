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
typedef long long ll;

ll dfs(int k, int x)
{
	if(x == 0) return 0;
	if(k == 0) return 1;
	if(x < (1 << (k - 1))) return dfs(k - 1, x);
	else return pow(3,k - 1) + 2 * dfs(k - 1, x - (1 << (k - 1)));
}

int main()
{
	int t; cin >> t;
	for( int i = 1; i <= t; ++i )
	{
		int k, a, b; cin >> k >> a >> b;
		cout << "Case " << i << ": " << dfs(k,(1 << k) - a + 1) - dfs(k,(1 << k) - b) << '\n';
	}
	return 0;
}

