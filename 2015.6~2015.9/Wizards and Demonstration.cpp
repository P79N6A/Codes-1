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
 	int n, x;
 	double y;
 	while(cin >> n >> x >> y)
 	{
 	    int need = ceil(y / 100.0 * n);
 	    if(need > x)
 	      cout << need - x << '\n';
 	    else cout << 0 << '\n';
    }
	return 0;
}

