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
int num[111];

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n; cin >> n;
	int even = 0, odd = 0;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if (x % 2) ++odd;
		else ++even;
	}
	if (odd % 2)
	{
		cout << odd << '\n';
	}
	else cout << even << '\n';
	return 0;
}

