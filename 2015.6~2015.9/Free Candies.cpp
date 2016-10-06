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
const int MAXN = 42;
int n, p[4][MAXN], dp[MAXN][MAXN][MAXN][MAXN], top[4];

int dfs(int len, bool color[])
{
    int& ret = dp[top[0]][top[1]][top[2]][top[3]];
    if (ret > 0) return ret;
    if (len == 5) return 0;
    for (int i = 0; i < 4; ++i)
    {
        if (top[i] == n) continue;
        int cur = p[i][top[i]];
        ++top[i];
        if (!color[cur])
        {
            color[cur] = 1;
            ret = max(ret, dfs(len + 1, color));
            color[cur] = 0;
        }
        else
        {
            color[cur] = 0;
            ret = max(ret, dfs(len - 1, color) + 1);
            color[cur] = 1;
        }
        --top[i];
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while(cin >> n && n)
	{
	    for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> p[j][i];
        bool color[25];
        memset(dp, 0, sizeof dp);
        memset(top, 0, sizeof top);
        memset(color, 0, sizeof color);
        cout << dfs(0, color) << '\n';
	}
	return 0;
}

