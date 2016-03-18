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
vector<int> divi;

int main()
{
 	int a, b, n, l, r; scanf("%d%d%d", &a, &b, &n);
 	int mx = __gcd(a, b);
 	for(int i = 1; i * i <= mx; ++i)
 	{
 	    if(mx % i == 0) 
        {
            if(i != mx / i)
                divi.push_back(i), divi.push_back(mx / i);
            else divi.push_back(i);
        }
    }
    sort(divi.begin(), divi.end());
 	for(int i = 0; i < n; ++i)
 	{
 	    scanf("%d%d", &l, &r);
 	    int p = upper_bound(divi.begin(), divi.end(), r) - divi.begin() - 1;
 	    if( l > divi[p] || r < divi[p]) printf("-1\n");
 	    else printf("%d\n", divi[p]);
    }
	return 0;
}

