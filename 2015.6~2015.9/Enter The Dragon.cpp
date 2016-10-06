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
const int MAXN = 1e6 + 111;
int which[MAXN];
int ans[MAXN];
int pp[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t; scanf("%d", &t);
	while( t --)
	{
	    memset(ans, 0, sizeof ans);
	    memset(pp, 0, sizeof pp);
	    int n, m, p = 0, cnt = 0;
	    bool flag = 0;
	    scanf("%d%d", &n, &m);
	    for(int i = 0; i < m; ++i) scanf("%d", &which[i]);
	    for(int i = 0; i < m; ++i)
	    {
	        if(!which[i])
	        {
                ++cnt;
            }
            else
            {
                if(cnt > p)
                {
                    if(pp[which[i]] < cnt)
                }
            }
        }
    }
	return 0;
}


