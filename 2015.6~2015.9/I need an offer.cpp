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
const int MAXN = 1e5 + 111;
int a[MAXN];
double b[MAXN], dp[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, m;
	while (scanf("%d%d", &n, &m) && (n || m))
	{
	    double ans = 1;
	    for (int i = 0; i <= n; ++i) dp[i] = 1;
	    for (int i = 0; i < m; ++i)
            scanf("%d%lf", &a[i], &b[i]), b[i] = 1 - b[i];
        for (int i = 0; i < m; ++i)
            for (int j = n; j >= a[i]; --j)
            {
                dp[j] = min(dp[j], dp[j - a[i]] * b[i]);
            }
        printf("%.1lf%%\n", (1 - dp[n]) * 100);
    }
	return 0;
}


