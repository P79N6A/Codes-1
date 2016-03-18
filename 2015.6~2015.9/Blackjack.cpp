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

int main()
{
	int n; cin >> n;
	if(n <= 10 || n > 21) cout << 0 << '\n';
	else if( n == 20 ) cout << 15 << '\n';
	else cout << 4 << '\n';
	return 0;
}

