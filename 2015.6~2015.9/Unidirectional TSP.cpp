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
typedef long long a;
int mp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int m, n;
	while( cin >> m >> n)
	{
	    memset(mp, 0x7f, sizeof mp);
	    for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
            {
                cin >> mp[i][j];
            }
        for(int j = n - 1; j >= 1; --j)
            for(int i = 1; i <= m; ++i)
            {
                if(i == 1)
                    mp[i][j] += min(mp[m][j + 1], min(mp[i][j + 1], mp[i + 1][j + 1]));
                else if ( i == m )
                    mp[i][j] += min(mp[i - 1][j + 1], min(mp[i][j + 1], mp[1][j + 1]));
                else
                    mp[i][j] += min(mp[i - 1][j + 1], min(mp[i][j + 1], mp[i + 1][j + 1]));
            }
        //for(int i = 1; i <= m; ++i, cout << '\n') for(int j = 1; j <= n; ++j) cout << mp[i][j] << ' ';
        vector<int> ans;
        int mi = mp[1][1], p = 1;
        for(int i = 1; i <= m; ++i)
        {
            if(mp[i][1] < mi)
            {
                mi = mp[i][1];
                p = i;
            }
        }
        ans.push_back(mi);
        ans.push_back(p);
        for(int i = 2; i <= n; ++i)
        {
            mp[0][i] = mp[m][i];
            mp[m + 1][i] = mp[1][i];
        }
        for(int j = 2; j <= n; ++j)
        {
            int nxmi = 0x7f7f7f7f, nxp = 0;
            if(p >= 2)
            {
                for(int i = p - 1; i <= p + 1; ++i)
                {
                    if(mp[i][j] < nxmi)
                    {
                        nxmi = mp[i][j];
                        nxp = i;
                    }
                }
                if(p == m)
                {
                    if(mp[p + 1][j] == nxmi)
                    {
                        nxp = p + 1;
                    }
                }
            }
            else
            {
                for(int i = p; i <= p + 1; ++i)
                {
                    if(mp[i][j] < nxmi)
                    {
                        nxmi = mp[i][j];
                        nxp = i;
                    }
                }
                if(mp[p - 1][j] < nxmi)
                {
                    nxmi = mp[p - 1][j];
                    nxp = p - 1;
                }
            }
            if(nxp == 0) nxp = m;
            if(nxp == m + 1) nxp = 1;
            p = nxp;
            ans.push_back(p);
        }
        cout << ans[1];
        for(int i = 2; i < ans.size(); ++i) cout << ' ' << ans[i];
        cout << '\n' << ans[0] << '\n';
    }
	return 0;
}


