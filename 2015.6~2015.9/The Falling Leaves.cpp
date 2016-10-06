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
const int MAXN = 1e3 + 111;
int sum[MAXN];

void build(int p)
{
	int v; cin >> v;
	if( v == -1 ) return;
	sum[p] += v;
	build(p - 1), build(p + 1);
}

bool init()
{
	int v; cin >> v;
	if( v == -1 ) return 0;
	memset(sum, 0, sizeof sum);
	int p = MAXN / 2;
	sum[p] = v;
	build(p - 1), build(p + 1);
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int kase = 0;
	while(init())
	{
		int p = 0;
		while(sum[p]==0) ++p;
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while( sum[p] != 0 ) cout << ' ' << sum[p++];
		cout << "\n\n";
	}
	return 0;
}

