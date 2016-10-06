#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned u;
u mx, mi, temp;

void print( u e )
{
	printf( "%u.%u.%u.%u\n", (e >> 24) , ((e<<8)>>24), ((e<<16)>>24) , ((e<<24)>>24));
}

int main()
{
	int a, b, c, d;
	int t;
	while( ~scanf("%d", &t) )
	{
		mx = 0, mi = ~0u;
		while( t -- )
		{
			scanf("%d.%d.%d.%d", &a, &b, &c, &d);
			temp = (a << 24) + (b << 16) + (c << 8) + d;
			mx = max(temp, mx);
			mi = min(temp, mi);
		}
		u mask;
		for(int i = 0 ; i <= 32 ; ++i)
		{
			mask = ~( (1ull << i) - 1);
			if((mask & mx) == (mask & mi))
				break;
		}
		mi = mi & mask;
		print( mi );
		print( mask ); 
	} 
	return 0;
}

