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

int main()
{
 	int n; 
    while( cin >> n)
    {
 	  ll x;
 	  ll sum = 0;
 	  for(int i = 1; i <= n; ++i)
 	  {
 	        cin >> x;
 	      sum += (x - 1) * i;
       }
       cout << sum + n << '\n';
    }
	return 0;
}

