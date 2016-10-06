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
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;
int t, m, n, mp[MAXN][MAXN], dp[MAXN][MAXN], dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int dfs(int x, int y)
{
    int& ret = dp[x][y];
    if (ret) return ret;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n)
        {
            if (mp[nx][ny] < mp[x][y])
            {
                ret = max(ret, dfs(nx, ny) + 1);
            }
        }
    }
    if (ret == 0) ret = 1;
    return ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	cin >> t;
	string name;
    while(t --)
    {
        cin >> name >> m >> n;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> mp[i][j];
                dp[i][j] = 0;
            }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int temp = dfs(i, j);
                ans = max(temp, ans);
            }
        cout << name << ": " << ans << '\n';
    }
	return 0;
}

