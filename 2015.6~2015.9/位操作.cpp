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

const int MAXN = 1e6 + 111;

int main()
{
	int r, x, y;
	while (~scanf("%p,%d,%d", &r, &x, &y))
	{
		int n = 1 << x; //将1向右移动x位 
		r = r & (~n);   //除x位外，其它位都变为1,此时进行与运算就能使得第x位置0 
		r = r | (1 << y); 
		r = r | (1 << (y - 1));
		n = 1 << (y - 2);
		r = r & ~n;
		printf("%x\n", r); 
	}
	return 0;
}

