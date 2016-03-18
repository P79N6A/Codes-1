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
bool vis[MAXN];
vector<int> v[MAXN];
int n, m; 

void dfs(int node)
{
    vis[node] = 1;
    for(int i = 0; i < v[node].size(); ++i)
    {
        if(!vis[v[node][i]])
        {
            dfs(v[node][i]);
        }
    }
}

int main()
{
 	cin >> n >> m;
 	int a, b;
 	for(int i = 0; i < m; ++i)
 	{
 	    cin >> a >> b;
 	    v[a].push_back(b);
 	    v[b].push_back(a);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            cout << "NO\n";
            goto label;
        }
    }
    if( m == n ) cout << "FHTAGN!\n";
    else cout << "NO\n";
    label:;
	return 0;
}

