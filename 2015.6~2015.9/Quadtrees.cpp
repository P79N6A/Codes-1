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
const int MAXN = 1024 + 10;
const int len = 32;
char s[MAXN];
int mp[len][len] , cnt;

void draw(const char* s, int& p, int r, int c, int w)
{
	char ch = s[p++];
	if( ch == 'p' )
	{
		draw(s, p, r,       c + w/2, w/2);
		draw(s, p, r,       c      , w/2);
		draw(s, p, r + w/2, c      , w/2);
		draw(s, p, r + w/2, c + w/2, w/2);
	}
	else if( ch == 'f')
	{
		for( int i = r; i < r + w; ++i )
			for( int j = c; j < c + w; ++j)
				if(mp[i][j] == 0)
				{
					mp[i][j] = 1; ++cnt;
				}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t; 
	scanf("%d", &t);
	while ( t -- )
	{
		memset(mp, 0, sizeof mp);
		cnt = 0;
		for( int i = 0; i < 2; ++i )
		{
			scanf("%s", s); 
			int p = 0;
			draw(s, p, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}

