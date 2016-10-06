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
const int MAXN = 1e4 + 111;
int num[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    int n;
    while (scanf("%d", &n) && n)
    {
        int sum = 0, mxsum = -1;
        for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
        int l, r, x, ll = num[0];
        for (int i = 0; i < n; ++i)
        {
            sum += num[i];
            if (sum > mxsum)
            {
                mxsum = sum;
                r = num[i];
                l = ll;
            }
            else if ( sum < 0)
            {
                ll = (i == n - 1 ? num[i] : num[i + 1]);
                sum = 0;
            }
        }
        if (mxsum < 0) printf("0 %d %d\n", num[0], num[n - 1]);
        else printf("%d %d %d\n", mxsum, l, r);
    }
	return 0;
}


