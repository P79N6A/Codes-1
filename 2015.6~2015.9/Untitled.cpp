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
int num[25], t, n, a, ans;
bool vis[25];

bool cmp(int a, int b)
{
    return a > b;
}

void dfs(int sum, int cnt, int x)
{
   // cout << sum << endl;
    if(sum == 0)
    {
        ans = min(ans, cnt);
        return;
    }
    for(int i = x; i < n; ++i)
    {
        if(sum % num[i] == sum) return;
        dfs(sum % num[i], cnt + 1, i + 1);
    }
    return;
}

int main()
{
 	cin >> t;
 	while( t --)
 	{
 	    cin >> n >> a;
 	    for(int i = 0; i < n; ++i)
 	      cin >> num[i];
 	    sort(num, num + n, cmp);
 	    ans = 0x3f3f3f3f;
 	    memset(vis, 0, sizeof vis);
 	    for(int i = 0; i < n; ++i)
 	    {
 	        dfs(a % num[i], 1, i + 1);
        }
        if(ans != 0x3f3f3f3f)
            cout << ans << '\n';
        else cout << -1 << '\n';
    }
	return 0;
}

