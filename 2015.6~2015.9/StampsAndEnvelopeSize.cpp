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
int stamp[15][15], dp[1111][11], s, n;

bool dfs(int set, int c, int cnt)
{
    int& ret = dp[c][cnt];
    if (ret != -1) return ret;
    if (!c) return ret = 1;
    if (!cnt) return ret = 0;
    for (int i = 1; i <= stamp[set][0]; ++i)
    {
        if (c >= stamp[set][i] && dfs(set, c - stamp[set][i], cnt - 1))
            return ret = 1;
    }
    return ret = 0;
}

int cmp(int a, int b)
{
    if (stamp[a][0] > stamp[b][0]) return b;
    if (stamp[b][0] > stamp[a][0]) return a;
    for (int i = stamp[a][0]; i >= 1; --i)
    {
        if (stamp[a][i] > stamp[b][i]) return b;
        if (stamp[b][i] > stamp[a][i]) return a;
    }
    return a;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    while (cin >> s && s)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> stamp[i][0];
            for (int j = 1; j <= stamp[i][0]; ++j)
                cin >> stamp[i][j];
        }
        int ans = 0, w = 0, k = 0;
        for (int i = 0; i < n; ++i)
        {
            memset(dp, -1, sizeof dp);
            for (int j = 1; ; ++j)
            {
                if (!dfs(i,j,s))
                {
                    k = j - 1;
                    break;
                }
            }
            if (k > ans)
            {
                ans = k;
                w = i;
            }
            else if (k == ans)
            {
                w = cmp(w,i);
            }
        }
        printf("max coverage =%4d :", ans);
        for (int i = 1; i <= stamp[w][0]; ++i)
            printf("%3d",stamp[w][i]);
        putchar('\n');
    }
	return 0;
}

