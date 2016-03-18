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
const int MAXN = 2e4;
struct P
{
    int s[8];
}p[MAXN];

int rnk[MAXN];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, kase = 0;
	double a[3];
	while( scanf("%d", &n) && n )
	{
	    for( int i = 1; i <= n; ++i ) 
        {
            scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
            for( int j = 0; j < 3; ++j ) p[i].s[j] = round(a[j] * 100.0);
            p[i].s[7] = p[i].s[0] + p[i].s[1] + p[i].s[2];
            p[i].s[6] = 0;
            for( int j = 3; j < 6; ++j)
            {
                p[i].s[j] = p[i].s[7] - p[i].s[j - 3];
            }
            sort(p[i].s, p[i].s + 8, cmp);
            //for(int j = 0; j < 8; ++j) cout << p[i].s[j] << endl;
        }
        for( int i = 1; i <= n; ++i ) scanf("%d", &rnk[i]);
        int ans = p[rnk[1]].s[0];
        int i;
        for( i = 2; i <= n; ++i )
        {
            bool flag = 1;
            int now = rnk[i], last = rnk[i - 1];
            for(int j = 0; j < 8; ++j)
            {
                if(ans == p[now].s[j] && now > last)
                {
                    flag = 0;
                    break;
                }
                if(p[now].s[j] < ans)
                {
                    ans = p[now].s[j];
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        printf("Case %d: ", ++kase);
        if(i != n + 1)
            printf("No solution\n");
        else printf("%.2lf\n", (double)ans/100.0);
    }
	return 0;
}

