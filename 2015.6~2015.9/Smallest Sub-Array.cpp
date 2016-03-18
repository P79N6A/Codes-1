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
const int MAXN = 1e6 + 111;
int x[MAXN];
int cnt[2000];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t, n, m, k;
	x[1] = 1, x[2] = 2, x[3] = 3;
	cin >> t;
	for(int kase = 1; kase <= t; ++kase)
	{
	    cin >> n >> m >> k;
	    int exist = 0;
	    memset(cnt, 0, sizeof cnt);
	    for( int i = 4; i <= n; ++i )  x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % m + 1;
	    int be = 1;
	    int ans = 0x3f3f3f3f;
	    for( int i = 1; i <= n; ++i)
	    {
	        if(exist == k)
	        {
	            --i;
	            cnt[x[be]]--;
	            if(cnt[x[be]] == 0 && x[be] <= k) --exist;
	            ++be;
	            if(exist == k) ans = min(ans, i - be + 1);
            }
            else
            {
                cnt[x[i]]++;
                if(cnt[x[i]] == 1 && x[i] <= k) ++exist;
                if(exist == k) ans = min(ans, i - be + 1);
            }
        }
        cout << "Case " << kase << ": ";
        if(ans != 0x3f3f3f3f) cout << ans << '\n';
        else cout << "sequence nai\n";
    }
	return 0;
}

