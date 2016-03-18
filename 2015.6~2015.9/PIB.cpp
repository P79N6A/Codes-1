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
const int MAXN = 111;
int hidep[MAXN];
int havep[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, num, ans = 0, mxhave= 0, have = 0, hide = 0; cin >> n;
	map<int, bool> mp;
    char op;
	for(int i = 1; i <= n; ++i)
	{
	    cin >> op >> num;
	    if(op == '+')
	    {
	        ++have;
	        mp[num] = 1;
        }
        else
        {
            if(mp[num] == 1)
            {
                mp[num] = 0;
                --have;
            }
            else
            {
                ++hide;
            }
        }
        hidep[i] = hide;
        havep[i] = have;
    }
    for(int i = 1; i <= n; ++i)
    {
        ans = max(ans, havep[i] + hidep[n] - hidep[i - 1]);
    }
    cout << ans << '\n';
	return 0;
}


