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
const int MAXN = 111;
vector<int> edge[MAXN];
int a[MAXN],n, m,x, y, ans = 0x3f3f3f3f; 
bool vis[MAXN];

void dfs(int node, int dep, int targe, int sum)
{
    if(dep == 4) return;
    for(int i = 0; i < edge[node].size(); ++i)
    {
        if(edge[node][i] == targe && dep == 3)
        {
            ans = min(ans, sum);
            return;
        }
        if(!vis[edge[node][i]])
        {
            vis[edge[node][i]] = 1;
            dfs(edge[node][i], dep + 1, targe, sum + a[edge[node][i]]);
            vis[edge[node][i]] = 0;
        }
    }
    return;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) 
    {
        cin >> x >> y;
	    edge[x].push_back(y);
	    edge[y].push_back(x);
    } 
    for(int i = 1; i <= n; ++i)
    {
        vis[i] = 1;
        dfs(i, 1, i, a[i]);
        vis[i] = 0;
    }
    cout << (ans == 0x3f3f3f3f? -1 : ans) << '\n';
	return 0;
}

