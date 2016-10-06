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
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 44;
char a[MAXN], b[MAXN];
int l[MAXN][MAXN];
ll c[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
 int t; scanf("%d",&t); getchar();
	for (int kase = 1; kase <= t; ++kase)
	{
  		gets(a + 1);
		gets(b + 1);
		int lena = strlen(a + 1), lenb = strlen(b + 1);
		memset(l, 0, sizeof l);
		memset(c, 0, sizeof c);
		for (int i = 0; i <= lena; ++i) c[i][0] = 1;
		for (int j = 0; j <= lenb; ++j) c[0][j] = 1;
		for (int i = 1; i <= lena; ++i)
			for (int j = 1; j <= lenb; ++j)
			{
				if(a[i] == b[j])
				{
					l[i][j] = l[i - 1][j - 1] + 1;
					c[i][j] = c[i - 1][j - 1];
				}
				else
				{
					if(l[i-1][j]>l[i][j-1])
                    {
                        l[i][j]=l[i-1][j];
                        c[i][j]=c[i-1][j];
                    }
                    else if(l[i][j-1]>l[i-1][j])
                    {
                        l[i][j]=l[i][j-1];
                        c[i][j]=c[i][j-1];
                    }
                    else
                    {
                        l[i][j]=l[i-1][j];
                        c[i][j]=c[i-1][j]+c[i][j-1];
                    }
				}
			}
		printf("Case #%d: %d %lld\n", kase,lena+lenb-l[lena][lenb] , c[lena][lenb]);
 	}
	return 0;
}

