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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
string name[30];
int len, n, m, mp[30][30];
bool vis[30];
map<string, int> id;

int getid(string na)
{
    int ret = id[na];
    if (ret != 0) return ret;
    id[na] = ++len;
    name[len] = na;
    return len;
}

void dfs(int u)
{
  vis[u] = 1;
  for(int i = 1 ; i <= n ; i++)
    if(mp[u][i] == 1 && mp[u][i] == mp[i][u])
    {
        if(!vis[i])
        {
            cout << ", " << name[i];
            dfs(i);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    while(cin >> n >> m && (n||m))
    {
        len = 0;
        string a, b;
        memset(mp, 0, sizeof mp);
        memset(vis, 0, sizeof vis);
        id.clear();
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            int ida = getid(a), idb = getid(b);
            mp[ida][idb] = 1;
        }
        for (int i = 1; i <= len; ++i)
            for (int j = 1; j <= len; ++j)if(mp[j][i])
                for (int k = 1; k <= len; ++k)if(mp[i][k])
                    mp[j][k] = 1;
        if (kase) cout << '\n';
        cout << "Calling circles for data set " << ++kase << ":\n";
        for (int i = 1; i <= len; ++i)
        {
            if(!vis[i])
            {
                cout << name[i];
                dfs(i);
                cout << '\n';
            }
        }
    }
    return 0;
}

