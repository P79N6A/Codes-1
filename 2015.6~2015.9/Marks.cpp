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
const int MAXN = 1e6 + 111;
int vis[110];

int main()
{
    string s[110];
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        char mx = '0';
        for (int j = 0; j < n; ++j)
        {
            mx = max(s[j][i],mx);
        }
        for (int j = 0; j < n; ++j)
        {
            if (s[j][i] == mx)
                vis[j] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (vis[i])
            ++ans;
    }
    cout << ans << '\n';
	return 0;
}

