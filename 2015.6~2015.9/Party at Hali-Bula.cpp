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
const int MAXN = 222;
int cnt, f[MAXN][2], dp[MAXN][2];
map<string, int> id;
vector<int> employee[MAXN];

int getID(string& name)
{
    int ID = id[name];
    if (ID) return ID;
    else id[name] = cnt++;
    //cout << name << ' ' << cnt - 1 << endl;
    return cnt - 1;
}

int dfs(int node, int pick)
{
    int& t = dp[node][pick];
    if (t >= 0) return t;
    int k = employee[node].size();
    if (!k)
    {
        f[node][pick] = f[node][!pick] = 1;
        if (pick) return t = 1;
        else return t = 0;
    }
    int ret = 0;
    if (pick)
    {
        ret = 1;
        f[node][pick] = 1;
        for (int i = 0; i < k; ++i)
        {
            ret += dfs(employee[node][i], 0);
            if (!f[employee[node][i]][0]) f[node][pick] = 0;
        }
    }
    else
    {
        f[node][pick] = 1;
        for (int i = 0; i < k; ++i)
        {
            if(dfs(employee[node][i],0) > dfs(employee[node][i],1))
            {
                ret += dp[employee[node][i]][0];
                if (!f[employee[node][i]][0])
                    f[node][pick] = 0;
            }
            else if(dfs(employee[node][i],0) < dfs(employee[node][i],1))
            {
                ret += dp[employee[node][i]][1];
                if (!f[employee[node][i]][1])
                    f[node][pick] = 0;
            }
            else
            {
                ret += dp[employee[node][i]][1];
                f[node][pick] = 0;
            }
        }
    }
    return t = ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	string boss, emp;
	while (cin >> n && n)
	{
	    cnt = 1;
	    for (int i = 0; i <= n; ++i) employee[i].clear();
	    memset(f, 0, sizeof f);
        memset(dp, -1, sizeof dp);
        id.clear();
        cin >> boss;
        id[boss] = cnt++;
        for (int i = 1; i < n; ++i)
        {
            cin >> emp >> boss;
            int ide = getID(emp), idb = getID(boss);
            //cout << emp << ":" << ide << endl;
            //cout << boss << ":" << idb << endl;
            employee[idb].push_back(ide);
        }
        int ans = max(dfs(1, 0), dfs(1, 1));
        cout << ans << ' ';
        if (dp[1][0] > dp[1][1])
        {
            if (f[1][0]) cout << "Yes\n";
            else cout << "No\n";
        }
        else if (dp[1][0] < dp[1][1])
        {
            if (f[1][1]) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "No\n";
    }
	return 0;
}
