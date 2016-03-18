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

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int a, b, n;
	while (cin >> n >> a >> b)
	{
		cout << min(n - a, b + 1) << '\n';
	}
	return 0;
}

