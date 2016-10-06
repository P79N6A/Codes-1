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
typedef long long ll;
const int MAXN = 2e3 + 11;
const ll MOD = 1e9 + 7;
ll c[MAXN][MAXN];

int main()
{
 	int n, m, k;
 	while (cin >> n >> m >> k)
 	{
 		memset(c, 0, sizeof c);
 		int mx = max(n, m);
 		for( int i = 0; i < mx; ++i)
 		{
 			for( int j = 0; j <= i; ++j)
			 {
			 	if (j == 0 || j == i) c[i][j] = 1;
			 	else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1])%MOD;
			} 
		}
 		cout << c[n - 1][2 * k] * c[m - 1][2 * k] % MOD << '\n';
	}
	return 0;
}

