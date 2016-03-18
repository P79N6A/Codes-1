#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

typedef unsigned long long ll;

const int MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	ll a = 0, b = 1;
	ll ans = 0;
	int c = -1;
	for (int i = 1; i < n; ++i)
	{
		a = 3 * b % MOD;
		b = (int)(a + c) % MOD;
		c = -c;
	}
	cout << a % MOD << '\n';
	return 0;
}

