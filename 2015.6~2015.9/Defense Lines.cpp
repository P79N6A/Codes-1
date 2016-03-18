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
const int MAXN = 2e5 + 111;
int l[MAXN], r[MAXN], h[MAXN], minv[MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n; cin >> t;
	while( t -- )
	{
	    cin >> n;
	    l[0] = r[n - 1] = 1;
	    for(int i = 0; i < n; ++i)
	    {
	        cin >> h[i];
	        if(i)
	        {
	            l[i] = 1;
	            if(h[i] > h[i - 1]) l[i] += l[i - 1];
            }
        }
        for(int i = n - 2; i >= 0 ; --i)
        {
            r[i] = 1;
            if(h[i] < h[i + 1]) r[i] += r[i + 1];
        }
        
        int ans = 0;
        memset(minv, 0x3f, sizeof minv);
        for(int i = 0; i < n; ++i)
        {
            int lb = lower_bound(minv + 1, minv + 1 + n, h[i]) - minv; //每一次寻找比当前h矮的最长的那个序列的长度 
            //cout << lb << "==============" << endl;
            ans = max(ans, r[i] + lb - 1);
            minv[l[i]] = min(minv[l[i]], h[i]);
        }
        cout << ans << '\n';
    }
	return 0;
}

