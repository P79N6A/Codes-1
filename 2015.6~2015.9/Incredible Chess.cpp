#include<iostream>
#include<cctype>
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
const int MAXN = 111;

int w[MAXN], b[MAXN];

int main()
{
	int t, n; scanf("%d", &t);
	for (int kase = 1; kase <= t; ++kase)
	{
	    int ans = 0;
	    scanf("%d", &n);
	    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
	    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	    for (int i = 0; i < n; ++i) ans ^= (b[i] - w[i] - 1);
        printf("Case %d: ", kase);
        if (!ans) printf("black wins\n");
        else printf("white wins\n");
	}
	return 0;
}

