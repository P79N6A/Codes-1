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
const int MAXN = 2e5 + 111;
char s1[MAXN];
char s2[MAXN];

bool same(char *a, char *b, int len)
{
	for (int i = 0; i < len; ++i)
		if (a[i] != b[i])
			return 0;
	return 1;
}

bool dfs(char *a, char *b, int len)
{
	if (len % 2)
	{
		if (same(a,b,len))
			return 1;
		else return 0;
	}
	else
	{
		int mid = len / 2;
		return (dfs(a, b + mid, mid) && dfs(a + mid, b, mid)
			||dfs(a, b, mid) && dfs(a + mid, b + mid, mid));
	}
}

int main()
{
	scanf("%s%s", s1, s2);
	int len = strlen(s1);
	if (dfs(s1, s2, len))
		puts("YES");
	else puts("NO");
	return 0;
}

