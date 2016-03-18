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
int dir[6] = {3, -2, 1, 3, -1, 2};
bool vis[20000];

int main()
{
 	int t, a, b, c, n; cin >> t;
 	while( t --)
 	{
 	    memset(vis, 0, sizeof vis);
 	    vector<int> ans;
 	    ans.push_back(0);
 	    cin >> a >> b >> c;
        n = a + b + c;
        int cnt = 0;
        int pre = 0;
        vis[0] = 1;
        while(a || b || c)
        {
            cnt %= 6;
            if((cnt == 0 || cnt == 3) && !c) {++cnt; continue;}
            if((cnt == 1 || cnt == 5) && !b) {++cnt; continue;}
            if((cnt == 2 || cnt == 4) && !a) {++cnt; continue;}
            if((cnt == 0 || cnt == 3) && c) --c;
            if((cnt == 1 || cnt == 5) && b) --b;
            if((cnt == 2 || cnt == 4) && a) --a;
            int nx = pre + dir[cnt];
            if(vis[nx]){++cnt;continue;}
            vis[nx] = 1;
            ans.push_back(nx);
            pre = nx;
            ++cnt;
        }
        cout << ans[0];
        for(int i = 1; i < ans.size(); ++i)
        {
            cout << ' ' << ans[i];
        }
        cout << '\n';
    }
	return 0;
}

