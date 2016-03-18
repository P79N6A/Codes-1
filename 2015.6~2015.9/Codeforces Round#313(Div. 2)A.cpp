#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e3 + 111;

int num[MAXN];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> num[i];
	sort(num, num + n);
	if (num[0] > 1)
		cout << 1 << '\n';
	else 
		cout << -1 << '\n'; 
	return 0;
}

