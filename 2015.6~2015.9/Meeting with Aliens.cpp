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
const int MAXN = 511;
int n, a[MAXN], p[MAXN];

int calc(int pos, int turn)
{
    int ta[MAXN], tp[MAXN];
    int cnt, j = pos;
    memcpy(ta, a, sizeof(a));
    memcpy(tp, p, sizeof(p));
    if(turn)
    {
        cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            int temp = tp[i];
            if(temp != j)
            {
                ++cnt;
                tp[ta[temp]] = j; tp[ta[j]] = temp;
                swap(ta[temp], ta[j]);
            }
            j = (j + 1)%n;
        }
        return cnt;
    }
    else
    {
        cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            int temp = tp[i];
            if(temp != j)
            {
                ++cnt;
                tp[ta[temp]] = j; tp[ta[j]] = temp;
                swap(ta[temp], ta[j]);
            }
            --j;
            if(j == -1) j = n - 1;
        }
        return cnt;
    }
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while( cin >> n && n )
	{
	    memset(a, 0, sizeof a);
	    memset(p, 0, sizeof p);
	    for(int i = 0; i < n; ++i)
	    {
            scanf("%d", a + i);
	        p[a[i]] = i;
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < n; ++i)
        {
            ans = min(ans, calc(i, 1));
            ans = min(ans, calc(i, 0));
        }
        cout << ans << '\n';
    }
	return 0;
}

